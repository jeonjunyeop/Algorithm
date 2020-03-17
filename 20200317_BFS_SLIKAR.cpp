//  SLIKAR 정올1082화염에서탈출
//  20200317_BFS_SLIKAR.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 3/17/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <queue>
using namespace std;
int N,M;
char table[50][50];
int fireTable[50][50];
int charactorTable[50][50];
int dir[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};
queue<pair<int, int>>fire;
queue<pair<int, int>>charactor;

void bfs(){
    
    while(!fire.empty()){
        int fy = fire.front().first;
        int fx = fire.front().second;
        fire.pop();
        
        for(int i=0; i<4; i++){
            int y = fy + dir[i][0];
            int x = fx + dir[i][1];
            if(0<=y&&y<N && 0<=x&&x<M && fireTable[y][x]==0 && table[y][x]== '.'){
                fireTable[y][x] = fireTable[fy][fx]+1;
                fire.push(make_pair(y, x));
            }
        }
    }
    
    while(!charactor.empty()){
        int cy = charactor.front().first;
        int cx = charactor.front().second;
        charactor.pop();
        
        for(int j=0; j<4; j++){
            int y = cy + dir[j][0];
            int x = cx + dir[j][1];
            if(0<=y&&y<N && 0<=x&&x<M && charactorTable[y][x]==0 && table[y][x]!='X'){
                if(fireTable[y][x]==0){
                    charactorTable[y][x] = charactorTable[cy][cx]+1;
                    charactor.push(make_pair(y, x));
                }
                else if(charactorTable[cy][cx]+1 < fireTable[y][x]){
                    charactorTable[y][x] = charactorTable[cy][cx]+1;
                    charactor.push(make_pair(y, x));
                }
            }
        }
    }
}

int main(){
    int destinationY=0, destinationX=0;
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>table[i][j];
            
            if(table[i][j]=='*'){
                fire.push(make_pair(i, j));
            }
            else if(table[i][j]=='S'){
                charactor.push(make_pair(i, j));
            }else if(table[i][j] == 'D'){
                destinationX = j;
                destinationY = i;
            }
        }
    }
    bfs();
    
    if(charactorTable[destinationY][destinationX]==0){
        cout << "impossible";
    }else{
        cout << charactorTable[destinationY][destinationX];
    }
//    cout <<"\n";
//    for(int i=0; i<N; i++){
//        for(int j=0; j<M; j++){
//            cout << table[i][j]<<" ";
//        }cout << "\n";
//    }cout << "\n";
//
//    for(int i=0; i<N; i++){
//        for(int j=0; j<M; j++){
//            cout << fireTable[i][j]<<" ";
//        }cout << "\n";
//    }cout << "\n";
//
//    for(int i=0; i<N; i++){
//        for(int j=0; j<M; j++){
//            cout << charactorTable[i][j]<<" ";
//        }cout << "\n";
//    }cout << "\n";
    
    return 0;
}


