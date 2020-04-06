// 정올1840 치즈
//  20200406_DFS_Cheese.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 4/6/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int N,M,cnt,cycle;
int table[100][100];
bool visited[100][100];
int dir[4][2]={{0,-1},{0,1},{1,0},{-1,0}};

void counting_cheese(){
    cnt=0;
    for(int i=0; i<N; i++)
        for(int j=0; j<M ;j++)
            if(table[i][j]==1)
                cnt++;
}

void air(){
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    while (!q.empty()) {
        int ay = q.front().first;
        int ax = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int y = ay + dir[i][0];
            int x = ax + dir[i][1];
            if(0<=y&&y<N && 0<=x&&x<M && visited[y][x]==0){
                if(table[y][x]==-1){
                    visited[y][x]=1;
                    q.push(make_pair(y, x));
                }else if(table[y][x]==0){
                    visited[y][x]=1;
                    table[y][x]=-1;
                    q.push(make_pair(y, x));
                }
            }
        }
    }
}


void melting_process(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(table[i][j]==1){
                for(int k=0; k<4; k++){
                    int y = i + dir[k][0];
                    int x = j + dir[k][1];
                    if(0<=y&&y<N && 0<=x&&x<M && table[y][x]==-1){
                        table[i][j]=2;
                        continue;
                    }
                }
            }
        }
    }
}
void two2one(){
    for(int i=0; i<N ;i++)
        for(int j=0; j<M; j++)
            if(table[i][j]==2)
                table[i][j]=-1;
}

bool stop_signal(){
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(table[i][j]!=-1)
                return false;
    return true;
}

void solution(){
    while(!stop_signal()){
        counting_cheese();
        air();
        memset(visited, 0, sizeof(visited));
        melting_process();
        two2one();
        cycle++;
    }
}

int main(){
    cin >>N>>M;
    for(int i=0; i<N ;i++)
        for(int j=0; j<M; j++)
            cin >> table[i][j];
            
    table[0][0]=-1;
    solution();
    cout << cycle<<"\n"<<cnt<<"\n";
    
    return 0;
}
