// 카드 구매하기 백준11052
//  20200327_DP_Purchasing cards.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 3/27/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <algorithm>
using namespace std;
int N;
int cards[1000];
int dp[1000];

//******* Time limit exceed *************
//void bf(int size, int idx, int value){
//    if(size>N || idx>N)
//        return;
//    if(size==N){
//        maxValue = max(maxValue, value);
//        return;
//    }
//
//    bf(size+idx, idx, value+cards[idx]);
//    bf(size, idx+1, value);
//} ******* Time limit exceed *************

void dynamicProgramming(){
    for(int i=1; i<=N; i++)
        for(int j=1; j<i; j++)
            dp[i] = max(dp[i], dp[i-j]+cards[j] );
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >>cards[i];
        dp[i]=cards[i];
    }
    //bf(0, 1, 0);
    dynamicProgramming();
    cout << dp[N];
    return 0;
}
