//  백준14502 연구소
//  20200418_Complex_Laboratory.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 4/18/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

queue<pair<int, int>>q;
int N,M, maxValue;
int table[8][8];
int dir[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
vector<pair<int, int>> virus(0);

void bfs(){
    int temp[8][8]={0,};
    for(int i=0; i<N; i++){
        for(int j=0; j<M ;j++){
            temp[i][j] = table[i][j];
        }
    }
    
    for(int i=0; i<virus.size(); i++)
        q.push(make_pair(virus[i].first, virus[i].second));

    while (!q.empty()) {
        int ay = q.front().first;
        int ax = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int y = ay+dir[i][0];
            int x = ax+dir[i][1];
            if(0<=y&&y<N && 0<=x&&x<M && temp[y][x]==0){
                temp[y][x]=3;
                q.push(make_pair(y, x));
            }
        }
    }
    
    int result = 0;
       for(int i=0; i<N ;i++){
           for(int j=0; j<M ;j++){
               if(temp[i][j]==0){
                   result++;
               }
           }
       }maxValue = max(maxValue, result);
    
}

void dfs(int count){
    if(count==3){
        bfs();
        return;
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(table[i][j]==0){
                table[i][j]=1;
                dfs(count+1);
                table[i][j]=0;
            }
        }
    }
}

int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> table[i][j];
            if(table[i][j]==2)
                virus.push_back(make_pair(i, j));
        }
    }
    dfs(0);
    cout << maxValue;
    return 0;
}

