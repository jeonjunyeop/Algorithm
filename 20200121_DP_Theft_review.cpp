//
//  20200121_DP_Theft_review.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 1/21/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.

#include <vector>
#include <unordered_set>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    vector<int> v;
    vector<int> w;
    v.resize(money.size(), money.at(0));
    w.resize(money.size(), money.at(1));
    w[0] = 0;
    
    for(int i=2; i<money.size(); i++){
        v[i] = max(v[i-1], v[i-2]+money[i]);
        w[i] = max(w[i-1], w[i-2]+money[i]);
    }
    answer = max(v[money.size()-2], w[money.size()-1]);
    return answer;
}

void assertions(vector<int> money, int answer){
    int t = solution(money);
    if(t==answer)
        cout <<"Correct!"<<endl;
    else{
        cout <<"Wrong!"<<endl;
        cout << t<<" ";
    }
}

int main(){
    assertions({1,2,3,1},4);
   
    return 0;;
}
