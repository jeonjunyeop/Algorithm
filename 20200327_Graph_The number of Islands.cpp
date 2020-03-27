// 섬의 개수 _ 백준4963
//  20200327_Graph_The number of Islands.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 3/27/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int w, h,cnt;
int table[50][50];
bool visited[50][50];
int dir[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

void dfs(int ay, int ax){
    visited[ay][ax]=1;
    for(int i=0; i<8; i++){
        int y = ay+dir[i][0];
        int x = ax+dir[i][1];
        if(0<=y&&y<h && 0<=x&&x<w && visited[y][x]==0 && table[y][x]==1){
            visited[y][x]=1;
            dfs(y, x);
        }
    }
}

void solution(){
    for(int i=0 ;i<h; i++){
        for(int j=0; j<w; j++){
            if(table[i][j]==1 && visited[i][j]==0){
                dfs(i, j);
                cnt++;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while(1){
        cnt=0;
        memset(visited, 0, sizeof(visited));
        memset(table, 0, sizeof(table));
        cin >> w >> h;
        
        if(w==0 && h==0)
            break;
        
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin >> table[i][j];
            }
        }
        
        solution();
        cout<< cnt<<"\n";
    }
    return 0;
}
