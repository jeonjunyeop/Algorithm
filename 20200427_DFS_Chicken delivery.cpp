// 백준15686 치킨 배달
//  20200427_DFS_Chicken delivery.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 4/27/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
int N,M, minVal=987654321;
int table[50][50];
int dir[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};
int chicken[13];
vector<int> v;
vector<pair<int, int>> ch(0);
vector<pair<int, int>> home(0);
int size;
int chicken_distance;

int distance_calculation(pair<int, int> a, pair<int, int> b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void dfs(int num, int count){
    if(num>size-1)
        return;
    if(count == M){
      
        for(int i=0; i<home.size(); i++){
            int temp=distance_calculation(home[i], ch[v[0]]);

            for(int j=1; j<v.size(); j++){
                temp = min(temp,distance_calculation(home[i], ch[v[j]]));

            }
            chicken_distance += temp;
        }
        minVal = min( minVal, chicken_distance);
        chicken_distance = 0;
        
        return;
    }

    v.push_back(num+1);
    //chicken[num+1]=1;
    dfs(num+1, count+1);
   // chicken[num+1]=0;
    v.pop_back();
    
    dfs(num+1, count);
}

int main(){
    
    cin >> N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N ; j++){
            cin >> table[i][j];
            if(table[i][j]==2){
                ch.push_back({i,j});
            }else if(table[i][j]==1){
                home.push_back({i,j});
            }
        }
    }
    size = ch.size();
    dfs(-1,0);
    
    cout <<minVal;
    
    return 0;
}
