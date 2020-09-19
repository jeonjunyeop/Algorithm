// 프로그래머스 _ 탐욕법 _ 큰 수 만들기
//  20200919_Greedy_MakingTheBiggestNumber.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 9/19/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int start_point =0;
    int total = number.size()-k;
    int end_point = number.size() - total;
    
    for(int i=0; i<total; i++){
        char temp= ' ';
        for(int j=start_point; j<=end_point; j++){
            if(temp < number[j]){
                temp = number[j];
                start_point = j+1;
            }
        }
        answer.push_back(temp);
        ++end_point;
    }
    
    return answer;
}

void assertions(string num, int k, string result){
    string answer = solution(num,k);
    if(answer == result){
        cout << "Correct answer \n";
    }else{
        cout << "Wrong answer \n";
    }
//
    cout << answer<<"\n";
    cout << result<<"\n\n";
}

int main(){
    assertions("1924", 2, "94");
    assertions("1294", 2, "94");
    assertions("1231234",3, "3234");
    assertions("4177252841",4, "775841");

    return 0;
}
