// 백준15685 드래곤 커브
//  20200422_SIM_Dragon curve.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 4/22/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, x, y, d, g;
int dir[4][2]= {{0,1},{-1,0},{0,-1},{1,0}};
int table[101][101];
void dragon_curve(){
    vector<int> direction(0);
    
    //0 Generation
    table[y][x]=1;
    direction.push_back(d);
    int cur_y = y+dir[d][0];
    int cur_x = x+dir[d][1];
    table[cur_y][cur_x]=1;

    
    for(int i=0; i<g; i++){ // 1~g Generation
        vector<int> copy = direction;
        int size = direction.size();
        
        for(int j=0; j<size; j++){
            int lastone = copy.back();
            copy.pop_back();
            int next_dir = (lastone+1)%4;
            direction.push_back(next_dir);
            cur_y += dir[next_dir][0];
            cur_x += dir[next_dir][1];
            table[cur_y][cur_x]=1;
        }
    }
}

int main(){
    cin >>N;
    for(int i=0; i<N; i++){
        cin >> x >> y >> d >> g;
        dragon_curve();
    }

    int answer =0;
    for(int i=0; i<101; i++){
        for(int j=0; j<101; j++){
            if(table[i][j]==1 && table[i+1][j]==1 && table[i][j+1]==1 && table[i+1][j+1]==1)
                answer++;
        }
    }
    cout <<answer;
    return 0;
}
