//// 도둑질_프로그래머스
//도둑이 어느 마을을 털 계획을 하고 있습니다. 이 마을의 모든 집들은 아래 그림과 같이 동그랗게 배치되어 있습니다.
//image.png
//각 집들은 서로 인접한 집들과 방범장치가 연결되어 있기 때문에 인접한 두 집을 털면 경보가 울립니다.
//각 집에 있는 돈이 담긴 배열 money가 주어질 때, 도둑이 훔칠 수 있는 돈의 최댓값을 return 하도록 solution 함수를 작성하세요.
//제한사항
//이 마을에 있는 집은 3개 이상 1,000,000개 이하입니다.
//money 배열의 각 원소는 0 이상 1,000 이하인 정수입니다.
//입출력 예
//money    return
//[1, 2, 3, 1]    4


//  20191227_DP_Theft.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 12/27/19.
//  Copyright © 2019 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int solution(vector<int> money) {
    int answer=0;
    vector<int> a;
    vector<int> b;
    
    a.resize(money.size(), money.at(0));
    b.resize(money.size(), money.at(1));
    b[0] = 0;
    
    for(int i=2; i<money.size()-1; i++)
        a[i] = max(a[i-2]+money[i], a[i-1]);
         
    for(int i=2; i<money.size(); i++)
        b[i] = max(b[i-2]+money[i], b[i-1]);
 
    a.pop_back();
    answer = max(a.back(), b.back());
   
    return answer;
}

void assertions(vector<int> money, int answer){
    int t = solution(money);
    if(t==answer)
        cout <<"Correct!"<<endl;
    else
        cout <<"Wrong!"<<endl;
}

int main(){
    assertions({1,2,3,1},4);
    assertions({1,2,3,1,2},5);
   
    return 0;;
}
