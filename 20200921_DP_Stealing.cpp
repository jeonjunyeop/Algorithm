// 프로그래머스_동적계획법_도둑질
//  20200921_DP_Stealing.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 9/21/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<int> money) {
    int answer = 0;
    int len = money.size();
    int dp[1000001][2]={0,};
    dp[0][0] = money[0];
    dp[1][1] = money[1];
    dp[2][1] = money[2];
    dp[1][0] = max(dp[0][0],money[1]);
    for(int i=2; i<len-1; i++)
        dp[i][0] = max(dp[i-1][0], dp[i-2][0]+money[i]);
    for(int i=2; i<len; i++)
        dp[i][1] = max(dp[i-1][1], dp[i-2][1]+money[i]);
    
//    for(int i=0; i<len; i++){
//        cout << dp[i][0]<< " ";
//    }cout <<"\n";
//    for(int i=0; i<len; i++){
//        cout << dp[i][1]<< " ";
//    }cout <<"\n";
        
    answer = max(dp[len-2][0],dp[len-1][1]);
    
    return answer;
}
void assertions(vector<int> money , int result){
    int answer = solution(money);
    if(answer == result){
        cout << "Correct answer! \n";
    }else{
        cout << "Wrong answer \n";
    }
    cout <<"Your answer: "<< answer<<"\n";
    cout <<"Provied answer: " << result<<"\n\n";
}

int main(){
    assertions({1,2,3,1},4);

    return 0;
}
