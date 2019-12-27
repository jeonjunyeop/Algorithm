//여행경로_프로그래머스
//주어진 항공권을 모두 이용하여 여행경로를 짜려고 합니다. 항상 ICN 공항에서 출발합니다.
//항공권 정보가 담긴 2차원 배열 tickets가 매개변수로 주어질 때, 방문하는 공항 경로를 배열에 담아 return 하도록 solution 함수를 작성해주세요.
//제한사항
//모든 공항은 알파벳 대문자 3글자로 이루어집니다.
//주어진 공항 수는 3개 이상 10,000개 이하입니다.
//tickets의 각 행 [a, b]는 a 공항에서 b 공항으로 가는 항공권이 있다는 의미입니다.
//주어진 항공권은 모두 사용해야 합니다.
//만일 가능한 경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로를 return 합니다.
//모든 도시를 방문할 수 없는 경우는 주어지지 않습니다.

//  20191227_BFS_Travel route.cpp
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

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    unordered_map<string, vector<string>> route;
    
    sort(tickets.begin(), tickets.end(), greater<vector<string>>());
    
    for(int i=0; i<tickets.size(); i++)
        route[tickets[i][0]].push_back(tickets[i][1]);
    
    vector<string> st = vector<string> {"ICN"};
    
    while(!st.empty()){
        string airport = st.back();
        if(route.find(airport)==route.end() || route[airport].size()==0){
            
            answer.push_back(airport);
            st.pop_back();
        }else{
            st.push_back(route[airport].back());
            route[airport].pop_back();
        }
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

void assertions(vector<vector<string>> tickets, vector<string> answer){
    vector<string> t = solution(tickets);
    if(t==answer)
        cout <<"Correct!"<<endl;
    else
        cout <<"Wrong!"<<endl;
}

int main(){
    assertions({{"ICN", "SFO"},{"ICN","ATL"},{"SFO","ATL"},{"ATL","ICN"},{"ATL","SFO"}},{"ICN","ATL","ICN","SFO","ATL","SFO"});
   
    return 0;;
}
