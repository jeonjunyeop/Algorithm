//
//  20200504_BFS_The moon is expanding,let's go.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 5/4/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cstring>

using namespace std;
int n,m;
char table[50][50];
bool visited[50][50][64];
int initial_y, initial_x;
queue<pair<pair<int, int>, pair<int, int>>>q;
int dir[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};

void bfs(){
    q.push({{initial_y,initial_x},{0,0}});
    while (!q.empty()) {
        int ay = q.front().first.first;
        int ax = q.front().first.second;
        int key = q.front().second.first;
        int movement = q.front().second.second;
        q.pop();
        if(table[ay][ax]=='1'){
            cout << movement;
            return;
        }
        
        for(int i=0; i<4; i++){
            int y = ay + dir[i][0];
            int x = ax + dir[i][1];
            if(0<=y&&y<n && 0<=x&&x<m && table[y][x]!='#' && visited[y][x][key]==0){
                if('a'<=table[y][x]&&table[y][x]<='f'){
                    int new_key = key|(1<<(int(table[y][x]-'a')));
                    visited[y][x][new_key] = 1;
                    q.push({{y,x},{new_key,movement+1}});
                }else if('A'<=table[y][x]&&table[y][x]<='F'){
                    if(key&(1<<(int(table[y][x]-'A')))){
                        visited[y][x][key]=1;
                        q.push({{y,x},{key,movement+1}});
                    }
                }else if(table[y][x]=='0' || table[y][x]=='1' || table[y][x]=='.'){
                    visited[y][x][key]=1;
                    q.push({{y,x},{key,movement+1}});
                }
            }
        }
    }
    cout <<-1;
}

int main(){
    cin >> n >> m;
    for(int i =0; i<n; i++){
        for(int j=0; j<m ;j++){
            cin >> table[i][j];
            if(table[i][j]=='0'){
                initial_y=i;
                initial_x=j;
            }
        }
    }
    bfs();
    return 0;
}
