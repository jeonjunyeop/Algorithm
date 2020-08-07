// 백준12100 2048 (Easy)
//  20200806_SIM_2048(Easy).cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 8/6/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n, answer=0;

int dir[4][2] ={{0,-1},{-1,0},{0,1},{1,0}};
void dfs(int table[][20], int direction, int cnt){
    if(cnt>5)
        return;
    
    int temp[20][20];
    bool visited[20][20]={0,};
    for(int i=0; i<n; i++) // Copy
        for(int j=0; j<n; j++)
            temp[i][j] = table[i][j];
    
    if(direction==0){ // W ---------------------------------------
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(temp[i][j]==0){
                    continue;
                }else{
                    int x = j;
                    while (1) {
                        x--;
                        if(x>=0){
                            if(visited[i][x]==0 && temp[i][x] == temp[i][x+1]){
                                temp[i][x+1] = 0;
                                temp[i][x] *= 2;
                                visited[i][x] = 1;
                                break;
                            }else if(temp[i][x] == 0){
                                temp[i][x] = temp[i][x+1];
                                temp[i][x+1] = 0;
                            }else
                                break;
                        }else
                            break;
                    }
                }
            }
        } // --------------------------------------- W
        
    }else if(direction==1){ // N ---------------------------------------
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(temp[j][i]==0){
                    continue;
                }else{
                    int y = j;
                    while (1) {
                        y--;
                        if(y>=0){
                            if(visited[y][i]==0 && temp[y][i] == temp[y+1][i]){
                                temp[y+1][i] = 0;
                                temp[y][i] *= 2;
                                visited[y][i]=1;
                                break;
                            }else if(temp[y][i] == 0){
                                temp[y][i] = temp[y+1][i];
                                temp[y+1][i] = 0;
                            }else{
                                break;
                            }
                        }else
                            break;
                    }
                }
            }
        } //--------------------------------------- N
        
    }else if(direction==2){ // E ---------------------------------------
        for(int i=0; i<n; i++){
            for(int j=n-1; j>=0; j--){
                if(temp[i][j]==0){
                    continue;
                }else{
                    int x = j;
                    while (1) {
                        x++;
                        if(x<n){
                            if(visited[i][x]==0 && temp[i][x] == temp[i][x-1]){
                                temp[i][x-1] = 0;
                                temp[i][x] *= 2;
                                visited[i][x] = 1;
                                break;
                            }else if(temp[i][x] == 0){
                                temp[i][x] = temp[i][x-1];
                                temp[i][x-1] = 0;
                            }else
                                break;
                        }else
                            break;
                    }
                }
            }
        } // --------------------------------------- E
        
    }else if(direction==3){ // S ---------------------------------------
        for(int i=0; i<n; i++){
            for(int j=n-1; j>=0; j--){
                if(temp[j][i]==0){
                    continue;
                }else{
                    int y = j;
                    while (1) {
                        y++;
                        if(y<n){
                            if(visited[y][i]==0 && temp[y][i] == temp[y-1][i]){
                                temp[y-1][i] = 0;
                                temp[y][i] *= 2;
                                visited[y][i] = 1;
                                break;
                            }else if(temp[y][i] == 0){
                                temp[y][i] = temp[y-1][i];
                                temp[y-1][i] = 0;
                            }else
                                break;
                        }else
                            break;
                    }
                }
            }
        }
        // --------------------------------------- S
    }else{
        //cout <<"Direction exception\n";
        //return;
    }
    
    //Update maximum value
//    cout <<"direction: "<<direction <<" count: "<<cnt<<"\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            answer = max(answer, temp[i][j]);
//            cout << temp[i][j] <<" ";
        }
//        cout <<"\n";
    }
//    cout <<"\n";

//    cout <<"Visited check\n";
//    for(int i=0; i<n; i++){
//        for(int j=0; j<n; j++){
//            cout << visited[i][j] <<" ";
//        }cout <<"\n";
//    }cout <<"\n";
    
    
    for(int i=0; i<4; i++){ // Next step
        //if(direction==i) *****
            //continue; // *****This must be deleted.
        dfs(temp,i,cnt+1);
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int table[20][20];
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> table[i][j];
    
    for(int i=0; i<4; i++)
        dfs(table,i,1);
    
    cout << answer<<"\n";
    return 0;
}
