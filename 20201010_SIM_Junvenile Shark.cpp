//
//  20201010_SIM_Junvenile Shark.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 10/10/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//

// Juvenile Shark
// 백준 19236 청소년 상어
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
// Return the maximum sum of fish
//Direction : 0,1,2,3,4,5,6,7 == N,NW,W,SW,S,SE,E,NE
int dir[8][2] = {{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
int max_value;
unordered_map<int, pair<pair<int, int>, int>> moving_fish(int table[][4], unordered_map<int, pair<pair<int, int>, int>>info){
    for(int i=1; i<=16; i++){
            if(info.count(i)){
                int d = info[i].second;
                int ay = info[i].first.first;
                int ax = info[i].first.second;
                int repeat = 8;
                while(repeat--){
                    int y = ay + dir[d][0];
                    int x = ax + dir[d][1];
                    // In table && No shark
                    if(0<=y&&y<4 && 0<=x&&x<4 && table[y][x]!=-1){
                        if(table[y][x]>0){ // Occupied
                            //Exchange
                            int moved_value = table[y][x];
                            table[y][x] = i;
                            table[ay][ax] = moved_value;
                            info[i].first = {y,x};
                            info[moved_value].first = {ay,ax};
                        }else{ // Empty
                            info[i].first = {y,x};
                            table[y][x] = i;
                            table[ay][ax] = 0;
                        }
                        info[i].second = d;
                        break;
                    }else{ // Rotate 45'
                        d = (d+1)%8;
                    }
                }
            }
        }
    return info;
}

unordered_map<int, pair<pair<int, int>, int>> Moving_shark(int sy, int sx, int next_sy, int next_sx, int table[][4], unordered_map<int, pair<pair<int, int>, int>> info){
    int food_number = table[next_sy][next_sx];
    table[sy][sx] = 0;
    table[next_sy][next_sx] = -1;
    info.erase(food_number);
    return info;
}

void dfs(int sy, int sx, int sd, int table[][4], unordered_map<int, pair<pair<int, int>, int>>info, int absorbed, int depth){
    max_value = max(max_value,absorbed);
//    cout << "stage: "<<depth <<"----------------\n";
//    for(int i=0; i<4; i++){
//        for(int j=0; j<4; j++){
//            cout << table[i][j] <<" ";
//        }cout <<"\n";
//    }cout <<absorbed<<"---\n";
    int copy_table[4][4];
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            copy_table[i][j] = table[i][j];
    
    unordered_map<int, pair<pair<int, int>, int>> copy_info = info;
    int y = sy+dir[sd][0];
    int x = sx+dir[sd][1];
    
    while (0<=y&&y<4 && 0<=x&&x<4) {
        if(table[y][x]>0){
//            cout <<"(" <<y<<","<<x<<")\n";
            int direction = info[table[y][x]].second;
//            cout << "direction: "<<direction<<"\n";
            int score = absorbed + table[y][x];
//            cout << "score: "<<score<<"\n";
            copy_info = Moving_shark(sy, sx, y, x, copy_table, copy_info);
            copy_info = moving_fish(copy_table, copy_info);
//            cout <<depth <<" ** moved table **\n";
//            for(int i=0; i<4; i++){
//                for(int j=0; j<4; j++){
//                cout << copy_table[i][j] <<" ";
//                }cout <<"\n";
//            }
            dfs(y, x, direction, copy_table, copy_info, score, depth+1);
            copy_info = info;
            for(int i=0; i<4; i++)
                for(int j=0; j<4; j++)
                    copy_table[i][j] = table[i][j];
        }
        y += dir[sd][0];
        x += dir[sd][1];
    }
//    cout <<"  -------------------------\n";
}

int main(){
    //Read the number and direction for each fish
    int num, direction;
    int sy=0, sx=0, sd=-1;
    int table[4][4];
    unordered_map<int, pair<pair<int, int>, int>> info;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cin >> num >> direction;
            table[i][j] = num;
            info[num] = {{i,j},direction-1};
        }
    }

    sd = info[table[0][0]].second; // Shark's direction
    int first_fish = table[0][0];
    // ---- First hunting ------
    info = Moving_shark(0, 0, 0, 0, table, info);
    // ----- First movement ----
    info = moving_fish(table, info);
    
//    for(int i=0; i<4; i++){
//        for(int j=0; j<4; j++){
//            cout << table[i][j] << " ";
//        }cout << "\n";
//    }cout <<"\n";
//    for(int i=0; i<4; i++){
//        for(int j=0; j<4; j++){
//            cout << info[table[i][j]].second << " ";
//        }cout << "\n";
//    }cout <<"\n";
    
    dfs(0, 0, sd, table, info, first_fish, 1);
    cout << max_value<<"\n";

    return 0;
}
