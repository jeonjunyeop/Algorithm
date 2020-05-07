// 미로만들기 백준2665
//  20200507_BFS_Making maze.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 5/7/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n,answer=987654321;
int table[50][50];
bool visited[50][50][100];
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
void bfs(){
    
    queue<pair<pair<int, int>, int>>q;
    q.push({{0,0},0});
    visited[0][0][0]=1;
    while (!q.empty()){
            int ay = q.front().first.first;
            int ax = q.front().first.second;
            int num = q.front().second;
            q.pop();
            if(ay==n-1 && ax==n-1){
                answer = min(answer,num);
            }
            
            for(int i=0;i<4; i++){
                int y = ay + dir[i][0];
                int x = ax + dir[i][1];
                if(0<=y&&y<n && 0<=x&&x<n && visited[y][x][num]==0){
                    if(table[y][x]==1){
                        visited[y][x][num]=1;
                        q.push({{y,x},num});
                    }else if(table[y][x]==0 && visited[y][x][num+1]==0){
                        visited[y][x][num+1] = 1;
                        q.push({{y,x},num+1});
                    }
                }
            }
    }
    
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%1d",&table[i][j]);
    
    bfs();
    cout << answer;

    return 0;
}
