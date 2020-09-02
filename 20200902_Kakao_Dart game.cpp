// 2018 KAKAO BLIND RECRUITMENT _ DART GAME
//  20200902_Kakao_Dart game.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 9/2/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int solution(string dartResult) {
    int answer = 0;
    int idx = 0;
    int value = 0;
    vector<int> v;
    while (idx<dartResult.size()) {
        char temp = dartResult[idx];
        
        if(temp == '*'){
            if(v.size())
                answer = answer +v.back() + (value*2);
            else
                answer += value*2;
            v.push_back({value*2});
            value = 0;
            
        }else if(temp == '#'){
            v.push_back(value*-1);
            answer += value*-1;
            value = 0;
        }
        
        else if(48<=temp&&temp<=57){
            if(value != 0){
                answer += value;
                v.push_back(value);
                value = 0;
            }
            
            if(temp==49 && dartResult[idx+1]==48){
                value = 10;
                idx++;
            }else{
                value = (int)(temp-'0');
            }
        }else if(temp == 'D'){
            value = pow(value, 2);
        }else if(temp == 'T'){
            value = pow(value, 3);
        }
        
        idx++;
    }
    answer += value;
    
    return answer;
}
void assertions(string s, int result){
    int answer = solution(s);
    if(answer == result){
        cout << "Correct answer \n";
    }else{
        cout << "Wrong answer \n";
    }
    cout << answer<<"\n";
    cout <<"\n";
}

int main(){
    assertions("1S2D*3T", 37);
    assertions("1D2S#10S", 9);
    assertions("1D2S0T", 3);
    assertions("1S*2T*3S", 23);
    assertions("1D#2S*3S", 5);
    assertions("1T2D3D#", -4);
    assertions("1D2S3T*", 59);
    
    return 0;
}
