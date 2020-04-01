// 백준1912연속합
//  20200401_DP_Continuous sum.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 4/1/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <algorithm>
using namespace std;
int n, maxValue;
int num[100001];
int dp[100001];

void dynammic_programming(){
    for(int i=1; i<n; i++){
        dp[i] = max(dp[i-1]+num[i], num[i]);
        maxValue = max(dp[i], maxValue);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++)
        cin >>num[i];
    maxValue = dp[0] = num[0];
    dynammic_programming();
    cout << maxValue<<"\n";  // Answer
//    for(int i=0; i<n;i++)
//        cout <<dp[i]<<" ";
    return 0;
}
