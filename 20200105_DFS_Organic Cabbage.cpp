// 유기농 배추 _ 백준 1012 
//  20200105_DFS_Organic Cabbage.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 1/5/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//


#include <iostream>
#include <cstring>
using namespace std;
int M,N,K;
bool lettuce[50][50];
bool visited[50][50];
int dir[4][2] = {{0,1},{0,-1}, {1,0}, {-1,0}};

void dfs(int y, int x){
    if(visited[y][x])
        return;
    visited[y][x]=1;

    for(int i=0; i<4; i++){
        int ny = y + dir[i][0];
        int nx = x + dir[i][1];
        if(0<=ny&&ny<N && 0<=nx&&nx<M && lettuce[ny][nx])
            dfs(ny, nx);
    }
}

int main(){
    int T;
    cin >> T;
    for(int tc = 0; tc < T; tc++){
        memset(visited, 0, sizeof(visited));
        memset(lettuce, 0, sizeof(lettuce));
        cin >> M >> N >>K;
        for(int i=0; i<K; i++){
            int a,b;
            cin>>a>>b;
            lettuce[b][a]=1;
        }
        int cnt=0;
        for(int i=0; i<N; i++)
            for(int j=0 ;j<M; j++)
                if(lettuce[i][j] && visited[i][j]==0){
                    dfs(i,j);
                    cnt++;
                }
        cout << cnt<<endl;
    }
    return 0;
}
