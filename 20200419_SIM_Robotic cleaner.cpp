//
//  20200419_SIM_Robotic cleaner.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 4/19/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N,M,r,c,direction;
int table[50][50];
queue<pair<int, int>> q;
int dir[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};
int num=3;
void bfs(){
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        //cout <<"("<<y <<","<<x<<") "<<direction<<"\n";
        
        //Clean the current location
        table[y][x] = num += 1;
        int k=0;
        while(1){
            direction = (direction+3)%4;
   
            if(direction==0 && 0<=y-1&&y-1<N &&0<=x&&x<M && table[y-1][x]==0){
                y--;
                q.push(make_pair(y, x));
                break;
            }else if(direction==1 && 0<=y&&y<N && 0<=x+1&&x+1<M && table[y][x+1]==0){
                x++;
                q.push(make_pair(y, x));
                break;
            }else if(direction==2 && 0<=y+1&&y+1<N &&0<=x&&x<M && table[y+1][x]==0){
                y++;
                q.push(make_pair(y, x));
                break;
            }else if(direction==3 && 0<=y&&y<N &&0<=x-1&&x-1<M && table[y][x-1]==0){
                x--;
                q.push(make_pair(y, x));
                break;
            }
            
            if(k==3){ // backward
                if(direction==0 && 0<=y+1&&y+1<N &&0<=x&&x<M && table[y+1][x]!=1){
                    y++;
                    q.push(make_pair(y, x));
                }else if(direction==1 && 0<=y&&y<N &&0<=x-1&&x-1<M && table[y][x-1]!=1){
                    x--;
                    q.push(make_pair(y, x));
                }else if(direction==2 && 0<=y-1&&y-1<N &&0<=x&&x<M && table[y-1][x]!=1){
                    y--;
                    q.push(make_pair(y, x));
                }else if(direction==3 && 0<=y&&y<N &&0<=x+1&&x+1<M && table[y][x+1]!=1){
                    x++;
                    q.push(make_pair(y, x));
                }else{
                    return;
                }
                break;
            }
            k++;
        }
    }
}

int main(){
    cin >> N >> M>> r >> c >>direction;
    q.push(make_pair(r, c));
    for(int i=0; i<N ;i++){
        for(int j=0; j<M ;j++){
            cin >> table[i][j];
        }
    }
    bfs();
    
    int result = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(table[i][j]>=3){
                result++;
            }
        }
    }
    cout << result;
    return 0;
}

