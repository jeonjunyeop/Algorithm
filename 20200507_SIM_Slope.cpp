//  경사로 백준14890
//  20200507_SIM_Slope.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 5/7/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int n,l,answer;
int table[100][100];

void solution(){
    // East
    for(int i=0; i<n; i++){
        int temp = table[i][0];
        int j=1;
        bool visited[100]={0,};
        while (j<n) {
            int current = table[i][j];
            int gap = current - temp;
            
            if(gap<-1 || gap > 1 ){
                break;
            
            }else if(gap==1){ // increase
                int cnt = 0;
                if(j-l>=0){
                    for(int k = j-l; k<j; k++){
                        if(table[i][k]==table[i][j]-1 && visited[k]==0){
                            cnt++;
                        }
                    }
                    if(cnt<l)
                        break;
                }else
                    break;
                
            }else if(gap==-1){ // decrease
                int cnt=0;
                if(j+l<=n){
                    for(int k = j+1; k<j+l; k++){
                        if(table[i][k]==table[i][j]){
                            cnt++;
                        }
                    }
                    if(cnt==l-1){
                        for(int k = j; k<j+l; k++){
                            visited[k]=1;
                        }
                    }else
                        break;
                        
                }else
                    break;
            }
            
            temp = table[i][j];
            j++;
            if(j==n){
//                cout << i <<","<< j<<"\n";
              answer++;
            }
            
        }
    }
//    cout <<"*******\n";
    
    //South
    for(int i=0; i<n; i++){
        int temp = table[0][i];
        int j=1;
        bool visited[100]={0,};
        while (j<n) {
            int current = table[j][i];
            int gap = current - temp;
            
            if(gap<-1 || gap > 1 ){
                break;
            
            }else if(gap==1){ // increase
                int cnt = 0;
                if(j-l>=0){
                    for(int k = j-l; k<j; k++){
                        if(table[k][i]==table[j][i]-1 && visited[k]==0){
                            cnt++;
                        }
                    }
                    if(cnt<l)
                        break;
                }else
                    break;
                
            }else if(gap==-1){ // decrease
                int cnt=0;
                if(j+l<=n){
                    for(int k = j+1; k<j+l; k++){
                        if(table[k][i]==table[j][i]){
                            cnt++;
                        }
                    }
                    if(cnt==l-1){
                        for(int k = j; k<j+l; k++){
                            visited[k]=1;
                        }
                    }else
                        break;
                        
                }else
                    break;
            }
            
            temp = table[j][i];
            j++;
            if(j==n){
//                cout << j <<","<< i<<"\n";
              answer++;
            }
        }
    }
    cout << answer;
}

int main(){
    cin >> n >> l;
    for(int i=0;i <n;i++){
        for(int j=0;j<n;j++){
            cin >> table[i][j];
        }
    }
    solution();
    return 0;
}
