// RGB 거리 _백준1149
//  20200123_DP_RGB Rd.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 1/23/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
   
    int N,minimum_value;
    cin >> N;
    vector<vector<int>> rgb(N, vector<int>(3));
    for(int i=0; i<N; i++){
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
    }
    vector<vector<int>> map(N, vector<int>(3,0));
    map[0][0] = rgb[0][0];
    map[0][1] = rgb[0][1];
    map[0][2] = rgb[0][2];
    
    for(int i=1; i<N; i++){
        for(int j=0; j<3; j++){
            if(j==0)
                map[i][j] = min(map[i-1][1],map[i-1][2]) + rgb[i][j];
            else if(j==1)
                map[i][j] = min(map[i-1][0],map[i-1][2]) + rgb[i][j];
            else
                map[i][j] = min(map[i-1][0],map[i-1][1]) + rgb[i][j];
        }
    }
    minimum_value =min(min(map[N-1][0],map[N-1][1]),map[N-1][2]);
    cout << minimum_value;
    return 0;
}

