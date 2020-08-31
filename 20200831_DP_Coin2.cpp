// Baekjoon 2294 Coin2
//  20200831_DP_Coin2.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 8/31/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n,k,temp;
    int coin[1000001];
    int dp[10001];
   // cout << "coin!\n";
    cin >>n >> k;
    
    for(int i=1; i<=100000; i++)
        dp[i] = 100000;
    
    for(int i=0; i<n; i++){
        cin >> temp;
        coin[i] = temp;
        dp[temp] = 1;
    }
    dp[0] = 0;
    for(int i=0; i<n; i++)
        for(int j=coin[i]; j<=k; j++)
            dp[j] = min(dp[j], dp[j-coin[i]]+1);

//    for(int i=0; i<=k; i++){
//
//        cout << i << " ";
//    }cout <<"\n";
//    for(int i=0; i<=k; i++){
//        if(i>=10 && dp[i]<10)
//                   cout <<" ";
//        cout << dp[i] <<" ";
//    }cout <<"\n";
    if(dp[k]==100000){
        cout << -1;
        return 0;
    }
    cout << dp[k];
    return 0;
}
