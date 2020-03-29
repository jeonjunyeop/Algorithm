// 퇴사 백준14501
//  20200329_Brute-force_Resignation.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 3/29/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N,maxValue;
int table[1000][2];
bool visited[1000];
void bf(int idx, int sum){
    if(visited[idx]!=0)
        return;
    if(idx>N)
        return;
    
    if(idx==N)
        maxValue=max(maxValue, sum);
    
    visited[idx]=1;
    bf(idx+table[idx][0], sum+table[idx][1]);
    bf(idx+1, sum);
    visited[idx]=0;
    
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> table[i][0] >> table[i][1];
    }
    bf(0,0);
    cout << maxValue;
    return 0;
}

