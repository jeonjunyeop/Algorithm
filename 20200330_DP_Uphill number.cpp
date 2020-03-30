// 백준11057 오르막 수
//  20200330_DP_Uphill number.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 3/30/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
using namespace std;
int N;
int num[1001][10];

int main(){
    cin >> N;
    for(int i=0; i<=9; i++)
        num[1][i] = 1;
    
    for(int i=2; i<=N; i++){
        for(int j=0; j<=9; j++){
            for(int k=0; k<=j; k++){
                num[i][j] += num[i-1][k];
                num[i][j] %= 10007;
            }
        }
    }
    int sum=0;
    for(int i=0; i<=9; i++)
        sum += num[N][i];
    cout << sum%10007;
    return 0;
}
