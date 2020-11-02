//
//  20201102_SIM_Magician&Fireball.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 11/2/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

// 백준 20056 마법사 상어와 파이어볼
// 시뮬레이션 Simulation

// 0,1,2,3,4,5,6,7 : N, NE, E, SE, S, SW, W, NW
int dir[8][2] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

struct INFO{
    int py;
    int px;
    int pm;
    int ps;
    int pd;
};
unordered_map<int, INFO> planet;

int main(){
    int n, m ,operation, answer = 0;;
    cin >> n >> m >> operation;
    int ey,ex,em,es,ed;
    for(int i=1; i<=m; i++){
        cin >> ey >> ex >> em >> es >> ed;
        planet[i] = {ey,ex,em,es,ed};
    }
    
    int idx = m+1;
    
    while (operation--) {
        vector<int> table[50][50];
        // -- 1. MOVE ------------------------
        for(auto & i : planet){
            int pid = i.first;
            int ay = i.second.py;
            int ax = i.second.px;
            int am = i.second.pm;
            int as = i.second.ps;
            int ad = i.second.pd;
            
            int y = (ay + (dir[ad][0]*as))%n;
            int x = (ax + (dir[ad][1]*as))%n;
            if(y<0)
                y+=n;
            if(x<0)
                x+=n;
            
            table[y][x].push_back(pid);
            i.second.py = y;
            i.second.px = x;
        }
        // ------------------------ 1. MOVE --/
        
        idx++;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(table[i][j].size()>1){
                    int mass = 0;
                    int second = 0;
                    int hol = 0;
                    int jak = 0;
                    int howmany = table[i][j].size();
                    for(int k=0; k<howmany; k++){
                        int pid = table[i][j][k];
                        mass += planet[pid].pm;
                        second += planet[pid].ps;
                        if(planet[pid].pd%2==0)
                            jak = 1;
                        else
                            hol = 1;
                        planet.erase(pid);
                    }
                    mass /= 5;
                    second /= howmany;
                    
                    
                    if(mass == 0){ // EXTINCT
                        continue;
                    }
                    if(hol==0 || jak==0){
                        planet[idx++] = {i,j,mass, second, 0};
                        planet[idx++] = {i,j,mass, second, 2};
                        planet[idx++] = {i,j,mass, second, 4};
                        planet[idx++] = {i,j,mass, second, 6};
                    }else{
                        planet[idx++] = {i,j,mass, second, 1};
                        planet[idx++] = {i,j,mass, second, 3};
                        planet[idx++] = {i,j,mass, second, 5};
                        planet[idx++] = {i,j,mass, second, 7};
                    }
                    
                }
            }
        }
        
        // PRINT
        /*cout << "TABLE\n";
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(table[i][j].size()==0)
                    cout <<"0";
                else
                    for(int k=0; k<table[i][j].size(); k++){
                        cout << table[i][j][k]<<",";
                    }
                cout <<"|";
            }cout <<"\n";
        }cout <<"\n";
        cout << "HASH\n";
        for(auto & i : planet){
            cout << i.first <<" : "<<i.second.py<<","<<i.second.px<<","<<i.second.pm<<","<<i.second.ps<<","<<i.second.pd<<"\n";
            
        }
        cout <<"----------------------------\n";
        */
        if(operation==0){
            for(auto& i : planet){
                answer += i.second.pm;
            }
        }
    }
    
    cout << answer<<"\n";
    
    return 0;
}
