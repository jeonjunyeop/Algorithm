// 프로그래머스 동적계획법(Dynamic programming) N으로 표현
//  20200921_DP_Express w) N.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 9/21/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <unordered_set>
using namespace std;

int solution(int N, int number) {
    int answer = -1;
    unordered_set<int> s[10];
    s[0].insert(0);
    int temp = N;
    for(int i=1; i<=8; i++){
        s[i].insert(temp);
        temp = temp*10 + N;
    }
    for(int i=1; i<=8; i++){
        for(int j=1; i+j<8; j++){
            for(auto& x : s[i]){
                for(auto & y : s[j]){
                    s[i+j].insert(x+y);
                    s[i+j].insert(x-y);
                    if(y>0)
                    s[i+j].insert(x/y);
                    s[i+j].insert(x*y);
                }
            }
        }
        if(s[i].count(number))
                return i;
    }

    return answer;
}

void assertions(int N, int number , int result){
    int answer = solution(N, number);
    if(answer == result){
        cout << "Correct answer \n";
    }else{
        cout << "Wrong answer \n";
    }
    cout << answer<<"\n";
    cout << result<<"\n\n";
}

int main(){
    assertions(5,12,4);
    assertions(5,2,3);
    assertions(2,11,3);
    assertions(5, 31168, -1);
   
    return 0;
}
