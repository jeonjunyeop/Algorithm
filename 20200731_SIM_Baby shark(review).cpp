//
//  20200731_SIM_Baby shark(review).cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 7/31/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int n;
int dir[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};
int table[20][20];
int total,sy,sx,size=2;
int consumed=0;
bool go = true;

void bfs(int initial_y, int initial_x){
    queue<pair<pair<int, int>, int>>q;
    q.push({{initial_y,initial_x},0});
    bool visited[20][20] = {0,};
    visited[initial_y][initial_x]=1;
    int limitation=0;
    
    vector<pair<int, int>>v;
    
    while (!q.empty()) {
        int ay = q.front().first.first;
        int ax = q.front().first.second;
        int dist = q.front().second;
//        cout << ay <<","<<ax<<"\n";
        q.pop();
        
        if(limitation!=0 && limitation<=dist)
            continue;
        
        for(int i=0; i<4; i++){
            int y = ay + dir[i][0];
            int x = ax + dir[i][1];
            if(0<=y&&y<n && 0<=x&&x<n && visited[y][x]==0){
                if(table[y][x]<size && table[y][x]!=0){ // edible
                    v.push_back({y,x});
                    limitation = dist+1;
                    visited[y][x]=1;
//                    cout <<y<<","<<x<<" pushed\n";
                }else if(table[y][x]==size || table[y][x]==0){
                    visited[y][x]=1;
                    q.push({{y,x},dist+1});
                }
            }
        }
    }
    if(v.size()>0){
        sort(v.begin(), v.end());
        sy = v[0].first;
        sx = v[0].second;
        table[sy][sx] = 9;
        table[initial_y][initial_x]=0;
        total += limitation;
//        cout <<"moved location: "<< sy <<","<<sx<<"\n";
//        cout <<"   +" <<limitation <<"\n";
        consumed++;
    }else{
        go = false;
    }
}


int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> table[i][j];
            if(table[i][j]==9){
                sy = i;
                sx = j;
            }
        }
    }
//    cout <<"shark: "<< sy <<","<< sx<<"\n";
    while (go) {
        bfs(sy, sx);
        if(consumed==size){
            size++;
            consumed=0;
        }
//        cout <<"----------------\n";
    }
    
    cout << total;
    return 0;
}
