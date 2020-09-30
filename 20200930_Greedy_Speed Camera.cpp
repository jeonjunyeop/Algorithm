// 프로그래머스 코딩테스트 연습 > 탐욕법 > 단속카메라
//  20200930_Greedy_Speed Camera.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 9/30/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    int len = routes.size();
    vector<pair<int, int>> r;
    for(int i=0; i<len ;i++){
        r.push_back({routes[i][0],routes[i][1]});
    }
    sort(r.begin(), r.end(), less<pair<int, int>>());
    int cam = r[0].second;
    for(auto& x : r){
        int a = x.first;
        int b = x.second;
        if(cam<a){ // No overlapped area
            answer ++;
            cam = b;
        }else if(cam>b){ // Inside
            cam = b;
        }else{ // Partially Overlapped
            continue;
        }
    }
    return answer;
}

void assertions(vector<vector<int>> routes, int result){
    int answer = solution(routes);
    if(answer == result){
        cout << "Correct answer! \n";
    }else{
        cout << "Wrong answer \n";
    }
    cout << answer<<"\n";
//    cout <<"Your answer: "<< answer<<"\n";
//    cout <<"Provied answer: " << result<<"\n\n";
//    for(auto &x : answer){
//        cout << x <<" ";
//    }cout <<"\n";
}

int main(){
    assertions({{-20,15},{-14,-5},{-18,-13},{-5,-3}}, 2);

    return 0;
}
