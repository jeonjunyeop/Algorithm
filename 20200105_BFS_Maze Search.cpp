// 미로 탐색 _백준2178
//  20200105_BFS_Maze Search.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 1/5/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int N,M;
queue<pair<int, int>> q;
int maze[100][100];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

void bfs(){
    q.push(make_pair(0, 0));
    
    pair<int, int> current;
    
    while(!q.empty()){
        current = q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            int x = current.second + dir[i][0];
            int y = current.first + dir[i][1];
            if(maze[y][x]==1){
                q.push(make_pair(y, x));
                maze[y][x]=maze[current.first][current.second] +1;
            }
        }
    }
    return;
}

int main(){
    cin >> N>> M;
    for(int i=0; i<N;i++)
        for(int j=0; j<M; j++)
            scanf("%1d",&maze[i][j]);
        
    bfs();
    cout<<maze[N-1][M-1];

    return 0;
}
