// 프로그래머스 _완전탐색 _모의고사
//  20200526_Brute-force_Mock test.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 5/26/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> first = {1,2,3,4,5};
    vector<int> second = {2,1,2,3,2,4,2,5};
    vector<int> third = {3,3,1,1,2,2,4,4,5,5};
    vector<pair<int, int>> v = {{0,1},{0,2},{0,3}};
    for(int i=0; i<answers.size(); i++){
        if(answers[i] == first[i%5])
            v[0].first++;
        if(answers[i] == second[i%8])
            v[1].first++;
        if(answers[i] == third[i%10])
            v[2].first++;
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());

    if(v[0].first == v[1].first && v[1].first == v[2].first){
        answer = {1,2,3};
    }else if(v[0].first == v[1].first){
        answer = {v[0].second, v[1].second};
    }else if(v[0].first!=0){
        answer.push_back(v[0].second);
    }else{
        answer = {0};
    }
    
    sort(answer.begin(), answer.end());

    return answer;
}

void assertion(vector<int> inanswers, vector<int> inreturn){
    vector<int> answer = solution(inanswers);
    if(answer == inreturn){
        cout << "Correct answer.\n";
    }else{
        cout << "Wrong answer.\n";
    }
}
int main(){
    assertion({1,2,3,4,5},{1});
    assertion({1,3,2,4,2},{1,2,3});
    
    return 0;
}
