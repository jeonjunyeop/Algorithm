// 벽부수고이동하기 _ 백준2206
//  20200501_BFS_Crash the wall and move.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 5/1/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int M,N;
int table[1000][1000];
int value[1000][1000][2];
bool visited[1000][1000];
int dir[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};
queue<pair<pair<int, int>, int>>q;
void bfs(){
    q.push({{0,0},0});
    value[0][0][0]=1;
    value[0][0][1]=1;

    while (!q.empty()) {
            int ay = q.front().first.first;
            int ax = q.front().first.second;
            int wall_break = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int y = ay+dir[i][0];
                int x = ax+dir[i][1];
                if(0<=y&&y<N && 0<=x&&x<M ){
                    if(table[y][x]==1 && wall_break==0){
                        value[y][x][1] = value[ay][ax][0]+1;
                        q.push({{y,x},1});
                    }else if(table[y][x]==0 && value[y][x][wall_break]==0){
                        visited[y][x]=1;
                        value[y][x][wall_break] = value[ay][ax][wall_break]+1;
                        q.push({{y,x},wall_break});
                    }
                }
            }
    }
    
}

int main(){
    cin >> N >>M;
    for(int i=0; i<N ; i++){
        for(int j=0; j<M; j++){
            scanf("%1d",&table[i][j]);
        }
    }
    bfs();
//    cout <<"\n";
//    for(int i=0; i<N; i++){
//        for(int j=0; j<M; j++){
//            if(value[i][j][0]<10)
//                       cout<<" ";
//            cout << value[i][j][0]<<" ";
//
//        }cout <<"\n";
//    }cout <<"\n";
//    for(int i=0; i<N; i++){
//        for(int j=0; j<M; j++){
//            if(value[i][j][1]<10)
//                           cout<<" ";
//            cout << value[i][j][1]<<" ";
//        }cout <<"\n";
//    }cout <<"\n";
//    cout << "end\n";
//
    if(value[N-1][M-1][0]==0 && value[N-1][M-1][1]==0){
        cout <<-1;
    }else{
        if(value[N-1][M-1][0]==0)
            cout <<value[N-1][M-1][1];
        else if(value[N-1][M-1][1]==0)
            cout <<value[N-1][M-1][0];
        else
            cout <<min(value[N-1][M-1][0], value[N-1][M-1][1]);
    }
    return 0;
}
