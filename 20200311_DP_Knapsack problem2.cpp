// 배낭채우기2 _정올1278
//  20200311_DP_Knapsack problem2.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 3/11/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//

//This question does not allow repeated use of jewelries
#include <iostream>
#include <algorithm>

using namespace std;
int N,maximumWeight, maximumValue;
int Wi[1000];
int Pi[1000];
int dp[10000];
bool visited[1000];

void knapsack(){
    for(int i=0; i<N; i++){
        for(int j=maximumWeight; j>=Wi[i]; j--){
            dp[j] = max(dp[j], Pi[i]+dp[j-Wi[i]]);
        }
    }
}

int main(){
 
    cin >> N>>maximumWeight;
    for(int i=0; i<N; i++){
        cin >> Wi[i] >>Pi[i];
    }
    knapsack();
    
    cout <<dp[maximumWeight]<<"\n";
    return 0;
}

