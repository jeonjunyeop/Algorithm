//
//  20200429_SIM_Laboratory3.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 4/29/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N,M;
int table[50][50];
vector<pair<int, int>> v;
int virus[10];
int dir[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};
int minVal=987654321;
void bfs(){
    int value[50][50] = {0,};
    queue<pair<int, int>> q;
    
    for(int i=0; i<v.size(); i++){
        if(virus[i]==1){
            int vy = v[i].first;
            int vx = v[i].second;
            q.push({vy, vx});
            value[vy][vx]=1;
        }
    }
    
    while (!q.empty()) {
        int ay = q.front().first;
        int ax = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int y = ay + dir[i][0];
            int x = ax + dir[i][1];
            if(0<=y&&y<N && 0<=x&&x<N && value[y][x]==0){
                if(table[y][x]==0 || table[y][x]==2){
                    value[y][x] = value[ay][ax]+1;
                    q.push({y,x});
                }
            }
        }
    }
    int maxval=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if (value[i][j]==0) {
                if(table[i][j]==2 || table[i][j]==0){
                    return;
                }
            }
            if(table[i][j]!=2)
                maxval = max(maxval,value[i][j]-1);
        }
    }
    //cout << maxval<<"\n";
    
//    for(int i=0; i<N; i++){
//        for(int j=0; j<N; j++){
//            cout << value[i][j]<<" ";
//        }cout <<"\n";
//    }cout <<"\n";
    minVal = min(minVal, maxval);
}

void dfs(int count, int num){
    if(num>v.size())
        return;
    if(count == M){
//        for(int i=0; i<10; i++){
//            if(virus[i]==1){
//                cout << i <<" ";
//            }
//        }cout <<"\n";
        
        bfs();
        return;
    }
    virus[num]=1;
    dfs(count+1, num+1);
    virus[num]=0;
    dfs(count, num+1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N>>M;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> table[i][j];
                if(table[i][j]==2){
                    v.push_back({i,j});
                }
        }
    }

    dfs(0,0);
    if(minVal==987654321)
        cout<<-1;
    else
        cout << minVal;
  
    return 0;
}
