// 백준16236 아기상어
//  20200506_SIM_Baby shark.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 5/6/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cstring>
using namespace std;
int n;
int table[20][20];
// bool visited[20][20];
int value[20][20];
int sha_y, sha_x, stop_line, hunting_time , kill;
int size=2;
typedef pair<int, int> p;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
void bfs(){
    while (1) {
            queue<pair<int, int>>q;
            vector<pair<int, int>>v(0);
            
            q.push({sha_y, sha_x});
            value[sha_y][sha_x]=0;
            
            while (!q.empty()) {
                    int ay = q.front().first;
                    int ax = q.front().second;
                    q.pop();
                    
                    if(stop_line>0 && value[ay][ax]>=stop_line){
                        break;
                    }
                    for(int i=0; i<4; i++){
                        int y = ay + dir[i][0];
                        int x = ax + dir[i][1];
                        if(0<=y&&y<n && 0<=x&&x<n && value[y][x]==0){
                            if(sha_y == y && sha_x == x){
                                continue;
                            }
                            if(table[y][x]==0){ // blank
                                value[y][x] = value[ay][ax]+1;
                                q.push({y,x});
                                
                            }else if(table[y][x]<size){ // edible fish
                                value[y][x] = value[ay][ax]+1;
                                stop_line = value[y][x];
                                //q.push({y,x});
                                v.push_back({y,x});
                            }else if(table[y][x]==size){ // passable fihs
                                value[y][x] = value[ay][ax]+1;
                                q.push({y,x});
                                
                            }
                        }
                    }
            }
        
//        for(int i=0; i<n; i++){
//            for(int j=0; j<n; j++){
//                cout << table[i][j]<<" ";
//            }cout <<"\n";
//        }cout <<"*********\n";
//        for(int i=0; i<n; i++){
//            for(int j=0; j<n; j++){
//                cout << value[i][j]<<" ";
//            }cout <<"\n";
//        }
            hunting_time += stop_line;
        
            if(v.empty()){ // No edible fish left
                cout <<hunting_time;
                return;
            }
            
            table[sha_y][sha_x] = 0;
            //The next location for the baby shark
            sort(v.begin(), v.end(), greater<>());
            sha_y = v.back().first;
            sha_x = v.back().second;
            v.clear();
            table[sha_y][sha_x] = 9;
            
            memset(value, 0, sizeof(value));
            stop_line = 0;
            
            //Level up
            kill ++;
            if(kill == size){
                size++;
                kill = 0;
            }
//        cout << "("<<sha_y <<","<<sha_x<<"),"<<size<<","<<kill<<", time:"<<hunting_time<<"\n";
    }
}

int main(){
    cin >>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >>table[i][j];
            if(table[i][j]==9){
                sha_y = i;
                sha_x = j;
            }
        }
    }
    bfs();
    
    return 0;
}
