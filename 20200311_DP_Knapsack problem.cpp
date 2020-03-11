// 배낭채우기1_정올 
//  20200311_DP_Knapsack problem.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 3/11/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <algorithm>

using namespace std;
int N,maximumWeight, maximumValue;
int Wi[1000];
int Pi[1000];
int dp[10000];

void knapsack(){
    for(int i=0; i<N; i++){
        for(int j=Wi[i]; j<=maximumWeight; j++){
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
    cout << dp[maximumWeight]<<"\n";
    
//    for(int i=0; i<=maximumWeight; i++){
//        cout <<i<<" "<< dp[i]<<"\n";
//    }
    
    return 0;
}

//void wrong_function(){
//    for(int i=0; i<=maximumWeight; i++){
//        for(int j=0; j<=4; j++){
//            if(i<Wi[j])
//                continue;
//            dp[i] = max(dp[i], dp[Wi[j]]+dp[i-Wi[j]]);
//        }
//    }
//}
//void wrong_function2(){
//    for(int i=0; i<4; i++){
//        for(int j=Wi[i]; j<=maximumWeight; j++){
//            dp[j] = max(dp[j], dp[Wi[i]]+dp[j-Wi[i]]);
//        }
//    }
//}
