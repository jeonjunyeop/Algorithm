// N 으로 표현하기 _ 프로그래머스
//  20200110_DP_Express w N.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 1/10/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <unordered_set>
using namespace std;

int solution(int N, int number) {
    int answer = -1;
    unordered_set<int> s[9];
    
    s[0].insert(N);
    int base = 1;
    for(int i =1 ;i<9; i++){
        base = base*10 + 1;
        s[i].insert(base*N);
    }
    
    for(int i = 1; i< 9 ; i++){
        for(int j=0; j<i; j++){
            for(auto& x : s[j]){
                for(auto& y : s[i-j-1]){
                    s[i].insert(x+y);
                    s[i].insert(x-y);
                    s[i].insert(x*y);
                    if(y!=0)
                    s[i].insert(x/y);
                }
            }
        }
        if(s[i].count(number)>0)
            return i+1;
    }

    return answer;
}

void assertions(int N, int number, int answer){
    int t = solution(N, number);
    if(t==answer)
        cout <<"Correct!"<<endl;
    else{
        cout <<"Wrong!"<<endl;
            cout << t<<" ";
    }
}

int main(){
    assertions(5, 12, 4);
    assertions(2, 11, 3);
    assertions(5, 31168, -1);
    
    return 0;;
}
