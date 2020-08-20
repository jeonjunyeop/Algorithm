//
//  20200820_SIM_King of fishing v2.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 8/20/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int R,C,M,sum;
int dir[5][2] = {{0,0},{-1,0},{1,0},{0,1},{0,-1}};

int main(){
    vector<pair<pair<int, int>, int>> table[101][101];
    cin >> R>> C>> M;
    int r,c,s,d,z;
    for(int i=0; i<M; i++){
        cin >> r >> c >> s >> d >> z;
        table[r][c].push_back({{s,d},z});
    }
    for(int i=1; i<=C; i++){

        //Fishing
        for(int j=1; j<=R; j++){
            if(table[j][i].size()){
                sum += table[j][i][0].second;
                table[j][i].clear();
                break;
            }
        }

        // Sharks' Movement
        //Push into the queue and clear the table.
        queue<vector<int>>q;
        for(int a = 1; a<=R; a++){
            for(int b = 1; b<=C; b++){
                if(table[a][b].size()){
                    q.push({a,b,table[a][b][0].first.first,table[a][b][0].first.second,table[a][b][0].second});
                    table[a][b].clear();
                }
            }
        }

        while (!q.empty()) {
            int ay = q.front()[0];
            int ax = q.front()[1];
            int speed = q.front()[2];
            int direction = q.front()[3];
            int size = q.front()[4];
            q.pop();
            for(int k = 0; k<speed; k++){
                if(direction==1 || direction == 2){
                    int next = ay + dir[direction][0];
                    if(next<1 || next >R )
                        direction = 3 - direction;
                    ay += dir[direction][0];
                }else{
                    int next = ax + dir[direction][1];
                    if(next<1 || next > C )
                        direction = 7 - direction;
                    ax += dir[direction][1];
                }
                
//                if(direction==1){
//                    if(ay==1){
//                        direction = 2;
//                    }
//                }else if(direction==2){
//                    if(ay==R){
//                        direction = 1;
//                    }
//                }else if(direction==3){
//                    if(ax == C){
//                        direction = 4;
//                    }
//                }else if(direction==4){
//                    if(ax == 1){
//                        direction = 3;
//                    }
//                }

//                ay += dir[direction][0];
//                ax += dir[direction][1];

            }

            if(table[ay][ax].size()){
                if(table[ay][ax][0].second < size){ // Edible
                    table[ay][ax].clear();
                    table[ay][ax].push_back({{speed,direction},size});
                }else{
                    continue;
                }
            }else{
                table[ay][ax].push_back({{speed, direction},size});
            }

        }



    }
    cout << sum;
    return 0;
}
