// 정올 2000 _동전교환
//  20200404_DP_Coin exchange.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 4/4/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,W;
int coin[10];
int dp[64001];
void dynamic_programming(){
    
    for(int i=0; i<N ;i++)
        for(int j = coin[i]; j<=W; j++)
            dp[j] = min(dp[j],dp[j-coin[i]]+1);
    
}
void initialization(){
    for(int i=1; i<=W; i++)
        if(dp[i]==0)
            dp[i] = 64002;
}

int main(){
    cin >>N;
    for(int i =0; i<N; i++){
        cin >> coin[i];
        dp[coin[i]]=1;
    }
    cin >> W;
    initialization();
    dynamic_programming();
    if(dp[W]==64002)
        cout<< "impossible";
    else
        cout << dp[W]<<"\n";
//    for(int i=0; i<=W; i++){
//        cout << i<<": "<<dp[i]<<"\n";
//    }
    return 0;
}
