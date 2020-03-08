// 보물섬 _ 정올1462
//  20200308_BFS_Treasure Island.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 3/8/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
char table[50][50];
int value[50][50];
int N,M,maxValue;
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
queue<pair<int, int>>q;

void treasureIsland(int pointY, int pointX){
    memset(value, 0, sizeof(value));
    value[pointY][pointX]=1;
    q.push(make_pair(pointY, pointX));

    while(!q.empty()){
        int aY = q.front().first;
        int aX = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int y = aY+dir[i][0];
            int x = aX+dir[i][1];
            if(0<=y&&y<N && 0<=x&&x<M){
                if(value[y][x]==0 && table[y][x]=='L'){
                    value[y][x] = value[aY][aX]+1;
                    maxValue = max(maxValue,value[y][x]);
                    //cout << maxValue<<" ";
                    q.push(make_pair(y, x));
                }
            }
        }
        
    }
//    for(int i=0; i<N; i++){
//        for(int j=0; j<M; j++){
//            cout << value[i][j]<<" ";
//        }cout<<"\n";
//    }cout <<"\n";
}

int main(){
    //int result = 0;
    cin >> N>>M;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> table[i][j];
        
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(table[i][j]=='L'){
                //cout <<i <<" "<<j<<"\n";
                treasureIsland(i,j);
            }
        }
    }
    cout << maxValue-1;
    return 0;
}
