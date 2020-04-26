// 백준 16234 인구 이동
//  20200426_BFS_Migration.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 4/26/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;
int N,L,R;
int table[50][50];
int temp[50][50];
bool visited[50][50];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

bool closed(){
    for(int i=0; i<N; i++)
        for(int j=0; j<N ;j++)
            if(temp[i][j]>0)
                return false;
    return true;
}

void bfs(int initial_y, int initial_x){
    queue<pair<int, int>> q;
    vector<pair<int, int>> v(0);
    v.push_back({initial_y,initial_x});
    q.push({initial_y,initial_x});
    visited[initial_y][initial_x]=1;
    int sum = table[initial_y][initial_x];
    int num=1;
    while (!q.empty()) {
            int ay = q.front().first;
            int ax = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int y = ay + dir[i][0];
                int x = ax + dir[i][1];
                if(0<=y&&y<N && 0<=x&&x<N && visited[y][x]==0){
                    if(L<=abs(table[y][x]-table[ay][ax]) && abs(table[y][x]-table[ay][ax])<=R){
                        visited[y][x]=1;
                        sum += table[y][x];
                        num++;
                        q.push({y,x});
                        v.push_back({y,x});
                    }
                }
            }
    }
    
    sum /= num;
    if(v.size()>1){
        for(int i=0; i<v.size(); i++){
            int ty = v[i].first;
            int tx = v[i].second;
            temp[ty][tx] = sum;
        }
    }
    
}

int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    cin >> N >> L >> R;
    for(int i=0; i<N ;i++){
        for(int j=0; j<N; j++){
            cin >>table[i][j];
        }
    }
    
    int cycle=0;
    while (1) {
            for(int i=0; i<N ;i++)
                for(int j=0; j<N; j++)
                    if(visited[i][j]==0)
                        bfs(i,j);
    
            if(closed()==true){
                cout << cycle<<"\n";
                break;
            }
            
            for(int i=0; i<N ;i++)
                for(int j=0; j<N; j++)
                    if(temp[i][j]>0)
                        table[i][j] = temp[i][j];
        
    //        for(int i=0; i<N ;i++){
    //            for(int j=0; j<N; j++){
    //                cout << table[i][j]<<" ";
    //            }cout <<"\n";
    //        }
            memset(visited, 0, sizeof(visited));
            memset(temp, 0, sizeof(temp));
            cycle++;
    }
    return 0;
}
