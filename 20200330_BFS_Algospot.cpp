// 알고스팟_ 백준1261
//  20200330_BFS_Algospot.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 3/30/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int table[100][100];
int value[100][100];

int dir[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
queue<pair<int, int>>q;
int N,M;
void bfs(){
    q.push(make_pair(0, 0));
    value[0][0]=0;
    
    while (!q.empty()) {
        int ay = q.front().first;
        int ax = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int y = ay + dir[i][0];
            int x = ax + dir[i][1];
            
            if(0<=y&&y<N && 0<=x&&x<M ){
                if(table[y][x]==1){
                    if(value[ay][ax]+1<value[y][x]){
                        value[y][x] = min(value[y][x], value[ay][ax]+1);
                        q.push(make_pair(y, x));
                    }
                }else if(table[y][x]==0){
                    if(value[y][x]>value[ay][ax]){
                        value[y][x] = min(value[y][x], value[ay][ax]) ;
                        q.push(make_pair(y, x));
                    }
                }
            }
        }
    }
}

int main(){
    cin>>M>> N;
    for(int i=0; i<N ;i++){
        for(int j=0; j<M ;j++){
            scanf("%1d",&table[i][j]);
            value[i][j]=987654321;
        }
    }
    bfs();
    cout << value[N-1][M-1]<<"\n";
//    for(int i=0; i<N; i++){
//        for(int j=0; j<M; j++){
//            cout <<value[i][j]<<" ";
//        }cout <<"\n";
//    }
    return 0;
}

