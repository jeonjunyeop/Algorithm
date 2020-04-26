// 백준11559 Puyo Puyo
//  20200426_SIM_Puyo Puyo.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 4/26/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

//**************************TIME LIMIT EXCEED**********************************
//******************************************************************************
//char table[12][6];
//int dir[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};
//bool visited[12][6];
//bool pop[12][6];
//queue<pair<int, int>>q;
//vector<pair<int, int>> total;
//
//bool finish(){
//    for(int i=0; i<12; i++){
//        for(int j=0; j<6; j++){
//            if(pop[i][j]==1){
//               return false;
//            }
//        }
//    }
//    return true;
//}
//
//void bfs(int initial_y, int initial_x){
//    q.push({initial_y,initial_x});
//    visited[initial_y][initial_x]=1;
//    vector<pair<int, int>> v;
//    v.push_back({initial_y,initial_x});
//    int num=1;
//    while (!q.empty()) {
//            int ay = q.front().first;
//            int ax = q.front().second;
//            q.pop();
//            for(int i=0; i<4; i++){
//                int y = ay +dir[i][0];
//                int x = ax + dir[i][1];
//                if(0<=y&&y<12 && 0<=x&&x<6 && visited[y][x]==0 && table[ay][ax] == table[y][x]){
//                    visited[y][x] =1;
//                    num++;
//                    v.push_back({y,x});
//                    q.push({y,x});
//
//                }
//            }
//    }
//    if(num>=4){
//        for(int i=0; i<v.size(); i++){
//            total.push_back(v[i]);
//            int vy = v[i].first;
//            int vx = v[i].second;
//           // cout << "("<<vy <<","<< vx <<")\n";
//            table[vy][vx]=0;
//            pop[vy][vx]=1;
//        }
//    }
//}
//
//int main(){
//
//    for(int i=0; i<12; i++){
//        for(int j=0; j<6; j++){
//            cin >> table[i][j];
//        }
//    }
//     int cycle=0;
//    while(1){
//        //cout <<"while\n";
//            vector<pair<int, int>>v(0);
//            for(int i=0; i<12; i++){
//                for(int j=0; j<6; j++){
//                    if(table[i][j]!='.'){
//                        v.push_back({i,j});
//                    }
//                }
//            }
//
//            for(int i=0; i<v.size(); i++){
//                int y = v[i].first;
//                int x = v[i].second;
//                if(visited[y][x]==0)
//                    bfs(y,x);
//            }
//
//
//            if(finish()==true){
//                cout << cycle;
//                break;
//            }
////
//            //re-organization
//            sort(total.begin(), total.end());
//            for(int i=0; i<total.size(); i++){
//                int y = total[i].first;
//                int x = total[i].second;
//                if(y>0){
//                    for(int j=y; j>0; j--){
//                        table[j][x] = table[j-1][x];
//                    }
//                }
//            }
//            memset(visited, 0, sizeof(visited));
//            memset(pop, 0, sizeof(pop));
//            total.clear();
//
//            cycle++;
//
////            for(int i=0; i<12; i++){
////                for(int j=0; j<6; j++){
////                    cout << table[i][j] <<" ";
////                }cout <<"\n";
////            }
//    }
//
//    return 0;
//}
//**************************TIME LIMIT EXCEED**********************************
//******************************************************************************

char table[13][6];
int dir[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};
bool visited[13][6];
bool pop[13][6];
queue<pair<int, int>>q;
//vector<pair<int, int>> total;

bool finish(){
    for(int i=0; i<13; i++)
        for(int j=0; j<6; j++)
            if(pop[i][j]==1)
               return false;
    return true;
}

void bfs(int initial_y, int initial_x){
    q.push({initial_y,initial_x});
    visited[initial_y][initial_x]=1;
    vector<pair<int, int>> v;
    v.push_back({initial_y,initial_x});

    int num=1;
    while (!q.empty()) {
            int ay = q.front().first;
            int ax = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int y = ay +dir[i][0];
                int x = ax + dir[i][1];
                if(0<y&&y<=12 && 0<=x&&x<6 && visited[y][x]==0 && table[ay][ax] == table[y][x]){
                    visited[y][x] =1;
                    num++;
                    v.push_back({y,x});
                    q.push({y,x});
                    
                }
            }
    }
    
        if(num>=4){
            for(int i=0; i<v.size(); i++){
                //total.push_back(v[i]);
                int vy = v[i].first;
                int vx = v[i].second;
                //cout << "("<<vy <<","<< vx <<")\n";
                table[vy][vx]='.';
                pop[vy][vx]=1;
            }
            sort(v.begin(), v.end());
            for(int i=0; i<v.size(); i++){
                int vy = v[i].first;
                int vx = v[i].second;
                for(int j= vy; j>0; j--){
                    table[j][vx] = table[j-1][vx];
                }
            }
        }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0; i<6; i++)
        table[0][i] = '.';
    
    for(int i=1; i<13; i++)
        for(int j=0; j<6; j++)
            cin >> table[i][j];

     int cycle=0;
    while(1){
            for(int i=1; i<13; i++){
                for(int j=0; j<6; j++){
                    if(table[i][j]!='.' && visited[i][j]==0){
                        bfs(i,j);
                    }
                }
            }
      
            if(finish()==true){
                cout << cycle;
                break;
            }

            memset(visited, 0, sizeof(visited));
            memset(pop, 0, sizeof(pop));
            cycle++;
    }
    
    return 0;
}
