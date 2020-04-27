// 17144 미세먼지 안녕!
//  20200427_SIM_Micro dust.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 4/27/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N,M,T;
int machine_y, machine_x, m2_y;
int table[50][50];
int dir[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};
void spread(){
    int temp[50][50]={0,};
    vector<pair<int, int>> v;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            temp[i][j] = table[i][j];
            if(table[i][j]>0){
                v.push_back({i,j});
            }
        }
    }
    
    for(int i=0; i<v.size(); i++){
        int ay = v[i].first;
        int ax = v[i].second;
        for(int i=0; i<4; i++){
            int y = ay+dir[i][0];
            int x = ax+dir[i][1];
            if(0<=y&&y<N && 0<=x&&x<M &&table[y][x]!=-1){
                temp[y][x] += table[ay][ax]/5;
                temp[ay][ax] -= table[ay][ax]/5;
            }
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            table[i][j] = temp[i][j];
        }
    }
    
}

void circulation(){
    
}

int main(){
    //Input
    int sum=0;
    cin >> N >> M >> T;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> table[i][j];
            if(table[i][j]==-1){
                if(machine_y ==0){
                    machine_y = i;
                    machine_x=j;
                }else
                    m2_y = i;
            }
        }
    }
    //cout <<"\n";
    
    for(int k=0; k<T; k++){
            //*****Spread
            spread();
            
//            for(int i=0; i<N ;i++){
//                for(int j=0; j<M; j++){
//                    cout << table[i][j]<<" ";
//                }cout << "\n";
//            }cout <<"\n";

            //******Circulation
            // Upper side
            for(int i=machine_y; i>0; i--) // South
                table[i][machine_x] = table[i-1][machine_x];
            
            for(int i=0; i<M-1; i++) // West
                table[0][i] = table[0][i+1];
            
            for(int i=0; i<machine_y; i++) // North
                table[i][M-1] = table[i+1][M-1];
            
            for(int i=M-1; i>1; i--) // East
                table[machine_y][i] = table[machine_y][i-1];
            
            table[machine_y][1] = 0;
            table[machine_y][machine_x]=-1;
            
            
            // Lower side
            for(int i=m2_y; i<N-1; i++) // North
                table[i][0] = table[i+1][0];
            
            for(int i=0; i<M-1; i++) // West
                table[N-1][i] = table[N-1][i+1];
            
            for(int i=N-1; i>m2_y; i--) // South
                table[i][M-1] = table[i-1][M-1];
            
            for(int i=M-1; i>1; i--) // East
                table[m2_y][i] = table[m2_y][i-1];
            
            table[m2_y][1] = 0;
            table[m2_y][machine_x]=-1;
        
            sum = 0;
//            for(int i=0; i<N ;i++){
//                for(int j=0; j<M; j++){
//                    cout << table[i][j]<<" ";
//                }cout << "\n";
//            }
            for(int i=0; i<N ;i++)
                for(int j=0; j<M; j++)
                    sum += table[i][j];

    }
    cout << sum+2;
    
    return 0;
}

