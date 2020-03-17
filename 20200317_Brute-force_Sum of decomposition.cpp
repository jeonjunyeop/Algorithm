// 분해합_백준2231
//  20200317_Brute-force_Sum of decomposition.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 3/17/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
using namespace std;

int N;
//int dp[1000000];
void operation(){
    int source =1;
    
    while(1){
        if(source>=N){
            cout << 0;
            break;
        }
        
        int sum = source;
        int copy = source;
        while(copy){
            sum+= copy%10;
            copy /= 10;
        }
        //dp[sum]=source;
        //cout << sum <<" "<<source<<"\n";
        
        if(sum==N){
            cout << source;
            break;
        }
        source++;
    }
}

int main(){
    cin >> N;
    operation();
    return 0;
}


