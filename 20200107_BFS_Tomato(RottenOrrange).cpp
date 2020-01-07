// 토마토 _ 백준7576, 정올2316
//  20200107_BFS_Tomato(RottenOrrange).cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 1/7/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int value[1000][1000];

int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
queue<pair<int, int>> q;
int m,n;
void bfs(){
    while(!q.empty()){
        pair<int, int> current = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int x = current.second + dir[i][0];
            int y = current.first + dir[i][1];
            
            if(0<=x&&x<m&& 0<=y&&y<n && value[y][x]==0){
                value[y][x] = value[current.first][current.second] + 1;
                q.push(make_pair(y, x));
            }
        }
    }
    return;
}

int main(){
    int maxv=0;
    cin >> m >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >>value[i][j];
            if(value[i][j]==1){
                q.push(make_pair(i, j));
            }
        }
    }

    bfs();
    
        for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(value[i][j]==0){
                cout << -1;
                return 0;
            }
            maxv = max(maxv , value[i][j]);
        }
    }

    cout << maxv-1;
  
    return 0;
}
