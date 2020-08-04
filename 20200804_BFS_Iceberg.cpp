// 백준2573 빙산
//  20200804_BFS_Iceberg.cpp
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

int n,m;
int table[300][300];
bool visited[300][300];
int dir[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};


void melting(){
    int temp[300][300]={0,};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(table[i][j]!=0){
                int cnt=0;
                for(int k=0; k<4; k++){
                    int y = i+dir[k][0];
                    int x = j+dir[k][1];
                    if(0<=y&&y<n && 0<=x&&x<m){
                        if(table[y][x]==0){
                            cnt++;
                        }
                    }
                }
                
                if(cnt>=table[i][j]){
                    temp[i][j]=0;
                }else{
                    temp[i][j] = table[i][j] - cnt;
                }
                
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(table[i][j]>0){
                table[i][j] = temp[i][j];
            }
        }
    }
    
}

void bfs(int initial_y, int initial_x){
    visited[initial_y][initial_x] =1;
    queue<pair<int, int>>q;
    q.push({initial_y,initial_x});
    while (!q.empty()) {
        int ay = q.front().first;
        int ax = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int y = ay + dir[i][0];
            int x = ax + dir[i][1];
            if(0<=y&&y<n&& 0<=x&&x<m){
                if(table[y][x]>0 && visited[y][x]==0){
                    visited[y][x]=1;
                    q.push({y,x});
                }
            }
        }
    }
}

int how_many(){
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(table[i][j]!=0){
                if(visited[i][j]==0){
                    bfs(i,j);
                    cnt++;
                }
            }else{
                visited[i][j]=1;
            }
        }
    }
    memset(visited, 0, sizeof(visited));
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >>table[i][j];
        }
    }
    int year=0;
    while (1) {
        year++;
        melting();
        int temp = how_many();
        //cout << temp<<"\n";
        if(temp>=2){
            cout<<year;
            return 0;
        }else if(temp==0){
            cout<<0;
            return 0;
        }
        
    }
    
    return 0;
}
