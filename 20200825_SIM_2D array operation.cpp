//
//  20200825_SIM_2D array operation.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 8/25/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
// 백준17140 이차원 배열과 연산
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <unordered_map>
using namespace std;

int r,c,k;
int table[100][100];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c >> k;
    r--; c--;
    for(int i=0;i <3; i++)
        for(int j=0;j<3; j++)
            cin >> table[i][j];
    
    int row = 3;
    int col = 3;
    int cycle = 0;
    while (1) {
        if(table[r][c]==k){
            cout << cycle<<"\n";
            return 0;
        }
        
        if(cycle>=100){
            cout << -1<<"\n";
            return 0;
        }
            
        if(row >= col){ // R Operation
            int temp=0;
            for(int i=0; i<row; i++){
                unordered_map<int, int>m;
                vector<pair<int, int>>v;
                for(int j=0; j<col; j++){
                    if(table[i][j]!=0){
                        m[table[i][j]]++;
                        table[i][j] =0;
                    }
                        
                }
                for(auto & x : m)
                    v.push_back({x.second,x.first});
                
                sort(v.begin(), v.end(), less<pair<int, int>>());
                int idx = 0;
                for(auto &x : v){
                    table[i][idx] = x.second;
                    table[i][idx+1] = x.first;
                    idx+=2;
                }temp = max(temp, idx);
            }
            col = temp;
            
        }else{ // C Operation
            int temp = 0;
            for(int i=0; i<col ;i++){
                unordered_map<int, int>m;
                vector<pair<int, int>>v;
                for(int j=0; j<row; j++){
                    if(table[j][i]!=0){
                        m[table[j][i]]++;
                        table[j][i]=0;
                    }
                }
                for(auto& x : m)
                    v.push_back({x.second,x.first});
                sort(v.begin(), v.end(), less<pair<int, int>>());
                int idx=0;
                for(auto & x : v){
                    table[idx][i] = x.second;
                    table[idx+1][i] = x.first;
                    idx+=2;
                }temp = max(temp, idx);
            }
            row = temp;
        }
//        for(int i=0; i<10; i++){
//            for(int j=0; j<10; j++){
//                cout << table[i][j] <<" ";
//            }cout <<"\n";
//        }cout <<"\n";
        cycle++;
    }
   
    return 0;
}
