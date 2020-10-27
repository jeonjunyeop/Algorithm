//
//  20201027_SIM_Fire Storm.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 10/27/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

// 백준 20058 마법사 상어와 파이어스톰
// 시뮬레이션 Simulation

int table[64][64];
bool visited[64][64];
int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
int n;

void rotation(int ay, int ax, int len){
    int copy_table[64][64];
    for(int i=ay; i<ay+len; i++) // INITIALIZAION
        for(int j=ay; j<ax+len; j++)
            copy_table[i][j] = 0;
 
    for(int i=0; i<len; i++)
        for(int j=0; j<len; j++)
            copy_table[ay+j][(ax+len-1)-i] = table[ay+i][ax+j];
    
    for(int i=ay; i<ay+len; i++) // UPDATE
        for(int j=ax; j<ax+len; j++)
            table[i][j] = copy_table[i][j];
}

void melting(){
    int copy_table[64][64];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            copy_table[i][j]=table[i][j];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int howmany = 0;
            for(int k=0; k<4; k++){
                int y = i+dir[k][0];
                int x = j+dir[k][1];
                if(0<=y&&y<n && 0<=x&&x<n){
                    if(table[y][x]>0){
                        howmany++;
                    }
                }
            }
            if(howmany<3 && table[i][j]>0)
                copy_table[i][j]--;
        }
    }
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            table[i][j]=copy_table[i][j];
}

int bfs(int initial_y, int initial_x){
    int sum = 1;
    queue<pair<int, int>>q;
    visited[initial_y][initial_x] = 1;
    q.push({initial_y,initial_x});
    while (!q.empty()) {
        int ay = q.front().first;
        int ax = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int y = ay + dir[i][0];
            int x = ax + dir[i][1];
            if(0<=y&&y<n && 0<=x&&x<n && table[y][x]>0 && visited[y][x]==0){
                q.push({y,x});
                visited[y][x] = 1;
                sum++;
            }
        }
    }
    return sum;
}

int size_count(){
    int maxsum = 0;
    memset(visited, 0, sizeof(visited));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(visited[i][j]==0 && table[i][j]>0)
                maxsum = max(maxsum, bfs(i,j));
    return maxsum;
}

int total_value(){
    int sum = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            sum += table[i][j];
    return sum;
}

int main(){
    int q;
    // -- INPUT ----------------
    cin >> n >> q;
    n = pow(2,n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> table[i][j];
 
    int level[1000];
    for(int i=0; i<q; i++)
        cin >> level[i];
    // ---------------- INPUT --/
    
    // -------------------------- OPERATION ------------
    int sum=0;
    for(int operation=0; operation<q; operation++){
        
        int len = pow(2, level[operation]);
        int y = 0;
        int x = 0;
        if(len>1){
            while (y!=n) {
                while (x!=n) {
                    rotation(y, x, len);
                    x+=len;
                }
                x=0;
                y+=len;
            }
        }
        // MELTING
        melting();
    }
    // -------------------------- OPERATION ------------/
    
    // PRINT
    /*for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << table[i][j]<<" ";
        }cout <<"\n";
    }cout <<"\n";*/
    cout <<total_value()<<"\n";
    cout <<size_count()<<"\n";
    return 0;
}
