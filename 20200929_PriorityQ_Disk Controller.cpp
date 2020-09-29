// 프로그래머스 _ 힙(Heap) _ 디스크 컨트롤러
//  20200929_PriorityQ_Disk Controller.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 9/29/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <cmath>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int num = jobs.size();
    priority_queue<pair<int, int>>pq;
    priority_queue<pair<int, int>> inner_q;
    for(int i=0; i<num; i++){
        pq.push({-jobs[i][0],-jobs[i][1]});
    }
    
    int ms = 0;
    while (!pq.empty()||!inner_q.empty()) {
        int start = -pq.top().first;
        int len = -pq.top().second;
        
        if(ms>=start && !pq.empty()){
            inner_q.push({-len, -start});
            pq.pop();
            continue;
        }else{
            if(!inner_q.empty()){
                int instart = -inner_q.top().second;
                int inlen = -inner_q.top().first;
                inner_q.pop();
                int added_value = inlen;
                if(ms>instart)
                    added_value+=ms-instart;
                answer+=added_value;
                ms+=inlen;
            }else{
                ms++;
            }
        }
    }
    return answer/num;
}

void assertions(vector<vector<int>> jobs, int result){
    int answer = solution(jobs);
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
    assertions({{0,3},{1,9},{2,6}}, 9);
    
    return 0;
}
