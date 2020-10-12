//
//  20201012_SIM_New Game2.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 10/12/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//

// New game 2
// 백준 17837 새로운 게임2
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
//0,1,2,3 : E,W,N,S
int dir[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
//nxn table, (White, Red, Blue)
//White : go and stacked (0)
//Red : go and stacked reversely (1)
//Blue : go opposite way (Stop when you cannot go) (2)
int color[12][12];
// number of units: k (1,2,3 ... k), each direction decided
int n, k;

bool game_over(vector<int> table[][12]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(table[i][j].size()>=4)
                return true;
        }
    }
        return false;
}

/* Draw the table and each direction. ------------------------
void print_table(vector<int> table[][12]){
    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            if(table[row][col].size()==0)
                cout <<0;
            for(int vi=0; vi<table[row][col].size(); vi++){
                cout << table[row][col][vi]<<",";
            }cout <<"|";
        }cout <<"\n";
    }cout <<"\n";
    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            if(table[row][col].size()==0)
                cout <<0;
            for(int vi=0; vi<table[row][col].size(); vi++){
                int arrow = info[table[row][col][vi]].second;
                if(arrow==0){
                    cout <<"->";
                }else if(arrow==1){
                    cout <<"<-";
                }else if(arrow==2){
                    cout <<"^";
                }else if(arrow==3){
                    cout <<"@";
                }else{
                    cout << "**** Exception *****\n";
                }
            }cout <<"|";
        }cout <<"\n";
    }cout <<"\n";
}
-------------------------------------------------------*/

int main(){
    cin >> n >> k;

    vector<int> table[12][12];
    unordered_map<int, pair<pair<int, int>, int>> info;

    // INPUT --------------------------
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> color[i][j];
        }
    }
    int a,b,c; // y,x,d
    for(int i=1; i<=k ;i++){
        cin >> a >> b >> c;
        info[i] = {{a-1,b-1},c-1};
        table[a-1][b-1].push_back(i);
    }
    // ------------------------- INPUT -//
    
    // -- SIMULATION --------------------------------------
    int turn =1;
    while (1) {
        if(turn>1000){
            cout << -1<<"\n";
            return 0;
        }

        for(int i=1; i<=k; i++){
            int ay = info[i].first.first;
            int ax = info[i].first.second;
            int d = info[i].second;
            vector<int> v = table[ay][ax];
            vector<int> selected;

            bool p = false;
            for(int j=0; j<v.size(); j++){
                if(v[j]==i && p==false){
                    p=true;
                }
                if(p==true){
                    selected.push_back(v[j]);
                    //table[ay][ax].erase(table[ay][ax].begin()+j); // Error generated
                }
            }
            for(int num =0; num<selected.size(); num++){
                table[ay][ax].pop_back();
            }

            int y = ay + dir[d][0];
            int x = ax + dir[d][1];

            //Blue
            if(y<0||y>=n||x<0||x>=n||color[y][x]==2){
                if(d==0||d==1){
                    d = 1-d;
                }else{
                    d = 5-d;
                }
                y = ay + dir[d][0];
                x = ax + dir[d][1];
                info[i].second = d;
            }

            bool moved = false;
            if(0<=y&&y<n && 0<=x&&x<n){

                if(color[y][x] == 0){ // White
                    moved = true;
                    for(auto& jason: selected){
                        table[y][x].push_back(jason);
                    }
                }else if(color[y][x] == 1){ // Red
                    moved = true;
                    reverse(selected.begin(), selected.end());
                    for(auto& jason: selected){
                        table[y][x].push_back(jason);
                    }
                }
            }
            if(moved==false){
                 for(auto& jason: selected){
                     table[ay][ax].push_back(jason);
                 }
            }else{
                for(auto & jason: selected){
                    info[jason].first = {y,x};
                }
            }
            
            if(game_over(table)==true){
                cout << turn<<"\n";
                return 0;
            }
        }
        
        turn ++;
    }
    // -------------------------------------------- SIMULATION --//
    return 0;
}
