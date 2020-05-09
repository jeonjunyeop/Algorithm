//
//  20200509_DFS_Tetromino.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 5/9/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n,m, value;
int table[500][500];
bool visited[500][500];
int dir[4][2] = {{0,-1},{1,0},{-1,0},{0,1}};

void dfs(int ay, int ax, int sum, int cells){
    if(cells==4){
        value = max(value, sum);
        return;
    }
    for(int i=0; i<4; i++){
        int y = ay + dir[i][0];
        int x = ax + dir[i][1];
        if(0<=y&&y<n && 0<=x&&x<m && visited[y][x]==0){
            visited[y][x] = 1;
            dfs(y,x,sum+table[y][x], cells+1);
            visited[y][x] = 0;
        }
    }
}

void solution(){
    
    // For the four types
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visited[i][j]=1;
            dfs(i,j,table[i][j], 1);
            visited[i][j]=0;
        }
    }
    
    //For the Extra type
    //South
    int sum = 0;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-2; j++){
            sum += table[i][j] + table[i][j+1] + table[i][j+2] + table[i+1][j+1];
            value = max(sum, value);
            sum = 0;
        }
    }
    //North
    for(int i=1; i<n; i++){
        for(int j=0; j<m-2; j++){
            sum += table[i][j] + table[i][j+1] + table[i][j+2] + table[i-1][j+1];
            value = max(sum, value);
            sum = 0;
        }
    }
    //East
    for(int i=0; i<n-2; i++){
        for(int j=0; j<m-1; j++){
            sum += table[i][j] + table[i+1][j] + table[i+2][j] + table[i+1][j+1];
            value = max(sum, value);
            sum = 0;
        }
    }
    //West
    for(int i=0; i<n-2; i++){
        for(int j=1; j<m; j++){
            sum += table[i][j] + table[i+1][j] + table[i+2][j] + table[i+1][j-1];
            value = max(sum, value);
            sum = 0;
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n ;i++){
        for(int j=0; j<m; j++){
            cin >> table[i][j];
        }
    }
    solution();
    cout << value;
    return 0;
}
