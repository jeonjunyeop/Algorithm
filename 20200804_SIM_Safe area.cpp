// 백준 2468 안전 영역
//  20200804_SIM_Safe area.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 8/4/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int n;
int dir[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
int table[100][100];
bool visited[100][100];

void bfs(int initial_y, int initial_x, int height){
    visited[initial_y][initial_x]=1;
    queue<pair<int, int>>q;
    q.push({initial_y,initial_x});
    while (!q.empty()) {
        int ay = q.front().first;
        int ax = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int y = ay + dir[i][0];
            int x = ax + dir[i][1];
            if(0<=y&&y<n && 0<=x&&x<n && visited[y][x]==0 && table[y][x]>height){
                visited[y][x]=1;
                q.push({y,x});
            }
        }
    }
}

int solution(int height){
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(table[i][j]>height){
                if(visited[i][j]==0){
                    bfs(i,j, height);
                    cnt++;
                }
            }else{
                visited[i][j]=1;
            }
        }
    }
    return cnt;
}

int main(){
    int result=0;
    cin >> n;
    int max_height=0;
    for(int i=0; i<n; i++){
        for(int j=0;j<n; j++){
            cin >> table[i][j];
            max_height = max(max_height, table[i][j]);
        }
    }
    
    for(int i=0; i<max_height; i++){
        int temp = solution(i);
        result = max(result,temp);
        //cout<< temp<<"\n";
        memset(visited, 0, sizeof(visited));
    }
    cout << result;
    return 0;
}
