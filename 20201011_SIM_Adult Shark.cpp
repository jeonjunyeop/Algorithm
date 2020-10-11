//
//  20201011_SIM_Adult Shark.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 10/11/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
// Adult Shark
// 백준 19237 어른 상어
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
//nxn table
//Number of shark : m
//Smell stays for k seconds
int n,m,k;

//N,S,W,E = 0,1,2,3
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

int priority[401][4][4];

//Smaller index shark kick out the bigger one.

bool game_over(pair<int, int>table[][20]){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(table[i][j].first>1 && table[i][j].second==k) // Shark's ID
                return false;
    return true;
}

void diminish(pair<int, int> table[][20]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(table[i][j].second==1){ // Remove
                table[i][j] = {0,0};
            }else if(table[i][j].second>0){
                table[i][j].second--;
            }
        }
    }
}

int main(){
    pair<int, int> table[20][20];
    // {{y,x},direction} for each shark
    unordered_map<int, pair<pair<int, int>, int>> info;
    
    // --- INPUT ----------------------------------
    cin >> n >> m >> k;
    int temp_value;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> temp_value;
            if(temp_value>0){
                info[temp_value] ={{i,j},-1};
                table[i][j] = {temp_value,k};
            }else{
                table[i][j] = {temp_value,0};
            }
        }
    }
    
    int direction;
    for(int i=1; i<=m; i++){
        cin>>direction;
        info[i].second = direction-1;
    }
    
    for(int i=1; i<=m; i++){
        for(int j=0; j<4; j++){
            for(int k=0; k<4; k++){
                cin >> priority[i][j][k];
                priority[i][j][k]--;
            }
        }
    }
    // ------------------------------------------
    // ------------ Simulation ------------------
    int seconds = 0;
    while (game_over(table)==false) {
        if(seconds>=1000){
            cout << -1<<"\n";
            return 0;
        }
        
        pair<int, int> copy_table[20][20];
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                copy_table[i][j] = {0,0};

        for(int i=1; i<=m; i++){
            if(info.count(i)){
                int ay = info[i].first.first;
                int ax = info[i].first.second;
                int d = info[i].second;
                bool needMySmell = true;
                for(int j=0; j<4; j++){
                    int next_d = priority[i][d][j];
                    int y = ay + dir[next_d][0];
                    int x = ax + dir[next_d][1];
                    // Avoid smell
                    // Kicked out by smaller one
                    // Update the direction
                    // In the boundary && No smell
                    if(0<=y&&y<n && 0<=x&&x<n){
                        if(table[y][x].second==0){
                        //Empty || kick out smaller one
//                        cout <<"ID: "<<i<<", idx: "<<j<<"\n";
//                        cout << "yx: ("<<y <<","<<x<<")\n";
//                        cout <<"origin: "<<d <<", next _ dir: "<<next_d <<"\n\n";
                            if(copy_table[y][x]==make_pair(0, 0) || copy_table[y][x].first>i){
                                copy_table[y][x] = {i,k};
                                info[i] = {{y,x},next_d}; // Update info
                            }else{
                                info.erase(i);
                            }
                            needMySmell = false;
                            break;
                        }
                    }
                }
                // ** Find the own smell
                if(needMySmell==true){
                    //cout << " ** generated ** \n";
                    for(int j=0; j<4; j++){
                        int next_d = priority[i][d][j];
                        int y = ay + dir[next_d][0];
                        int x = ax + dir[next_d][1];
                        if(0<=y&&y<n && 0<=x&&x<n && table[y][x].first==i){
                            if(copy_table[y][x]==make_pair(0, 0) || copy_table[y][x].first>i){
                                copy_table[y][x] = {i,k};
                                info[i] = {{y,x},next_d}; // Update info
                            }else{
                                info.erase(i);
                            }
                            break;
                        }
                    }
                }
            }
        }
        diminish(table);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(copy_table[i][j]!=make_pair(0, 0)){
                    table[i][j] = copy_table[i][j];
                }
            }
        }
//        cout << seconds <<"--------\n";
//        for(int i=0; i<n; i++){
//            for(int j=0; j<n; j++){
//                cout << "("<<table[i][j].first <<"," <<table[i][j].second<<") ";
//            }cout <<"\n";
//        }cout <<"\n";
        seconds++;
    }
    // ------------------------------------------
    cout << seconds<<"\n";
    return 0;
}
