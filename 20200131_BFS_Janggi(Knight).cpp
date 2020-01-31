// 장기 _ 정올 1106
//  20200131_BFS_Janggi(Knight).cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 1/31/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N,M;
int horseY, horseX, soldierY, soldierX;
int table[101][101];
bool visited[102][102]={0,};
int moving[8][2] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
queue<pair<int, int>>q;

void bfs(){
    q.push(make_pair(horseY, horseX));
    visited[horseY][horseX]=1;
    table[horseY][horseX]=0;
    //cout<<"start point"<<endl;
    
    while(1){
        pair<int, int> current = q.front();
        q.pop();
       // cout<< "queue"<<endl;
        for(int i=0; i<8; i++){

            int y = current.first + moving[i][0];
            int x = current.second + moving[i][1];

            if(1<=y&&y<=N && 1<=x&&x<=M && visited[y][x]!=1){
                if(y==soldierY && x==soldierX){
                    table[y][x]=table[current.first][current.second]+1;
                    //cout<<"return point"<<" y="<<y<<" x="<<x<<endl;
                    return;
                }
                table[y][x]=table[current.first][current.second]+1;
                q.push(make_pair(y, x));
                visited[y][x]=1;
            }
        }
    }
}

int main(){
    cin >> N >> M;
    cin >> horseY >> horseX >> soldierY >> soldierX;
    if(horseX==soldierX && horseY==soldierY)
        return 0;
    bfs();
    cout << table[soldierY][soldierX];
    //cout << answer<<endl;
    
//    for(int i=1; i<=N; i++){
//        for(int j=1; j<=M; j++){
//            cout<< table[i][j]<<" ";
//        }cout<<endl;
//    }
//    cout<< horseY <<" "<<horseX<<" "<<soldierY<<" "<<soldierX<<endl<<endl;
//
//    for(int i=1; i<=N; i++){
//        for(int j=1; j<=M; j++){
//            cout<< visited[i][j]<<" ";
//        }cout<<endl;
//    }
//
    return 0;
}
