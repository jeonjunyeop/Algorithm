// 백준1600 말이 되고픈 원숭이
//  20200502_BFS_Monkey wanna be a horse.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 5/2/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int M,N,K;
int table[200][200];
bool visited[200][200][30];
int dir[12][2] = {{-1,-2},{-2,-1},{1,-2},{2,-1},{-2,1},{-1,2},{1,2},{2,1},{0,-1},{0,1},{1,0},{-1,0}};
//int dir1[4][2] ={{0,-1},{0,1},{1,0},{-1,0}};
//int dir2[8][2] ={{-1,-2},{-2,-1},{1,-2},{2,-1},{-2,1},{-1,2},{1,2},{2,1}};

int bfs(){
    queue<pair<pair<int, int>, pair<int, int>>>q;
    q.push({{0,0},{0,0}});
    visited[0][0][0]=1;
   
    while (!q.empty()) {
            int ay = q.front().first.first;
            int ax = q.front().first.second;
            int horse_movement = q.front().second.first;
            int value = q.front().second.second;
            //cout << "("<<ay <<"," <<ax <<")" <<horse_movement<<","<<value<<"\n";
            q.pop();
        
            if(ay==N-1 && ax==M-1){
                return value;
            }
            
            for(int i=0; i<12; i++){
                if(horse_movement==K && i<8)
                        continue;
                int y = ay+dir[i][0];
                int x = ax+dir[i][1];
                if(0<=y&&y<N && 0<=x&&x<M && table[y][x]==0){
                    if(i<8 && visited[y][x][horse_movement+1]==0){
                        visited[y][x][horse_movement+1] = 1;
                        q.push({{y,x},{horse_movement+1,value+1}});
                    }
                    else if(i>=8 && visited[y][x][horse_movement]==0){
                        visited[y][x][horse_movement] = 1;
                        q.push({{y,x},{horse_movement,value+1}});
                    }

                }
            }
//Faster
//            if(horse_movement<K){
//                for(int i=0; i<8; i++){
//
//                    int y = ay+dir2[i][0];
//                    int x = ax+dir2[i][1];
//                    if(0<=y&&y<N && 0<=x&&x<M && visited[y][x][horse_movement+1]==0 && table[y][x]==0){
//                         visited[y][x][horse_movement+1] = 1;
//                         q.push({{y,x},{horse_movement+1,value+1}});
//                    }
//                }
//
//            }
//            for(int i=0; i<4; i++){
//
//                int y = ay+dir1[i][0];
//                int x = ax+dir1[i][1];
//                if(0<=y&&y<N && 0<=x&&x<M && visited[y][x][horse_movement]==0 && table[y][x]==0){
//                    visited[y][x][horse_movement] = 1;
//                    q.push({{y,x},{horse_movement,value+1}});
//                }
//            }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >>K >> M >>N;
    for(int i=0; i<N ; i++){
        for(int j=0; j<M; j++){
            cin >> table[i][j];
        }
    }
    cout << bfs();

    return 0;
}
