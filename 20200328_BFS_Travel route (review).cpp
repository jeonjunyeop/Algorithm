//
//  20200328_BFS_Travel route (review).cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 3/28/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    unordered_map<string, vector<string>> route;
    sort(tickets.begin(), tickets.end(), greater<vector<string>>());
    for(int i=0; i<tickets.size(); i++)
        route[tickets[i][0]].push_back(tickets[i][1]);
    
    vector<string> st = vector<string>{"ICN"};
    
    while(!st.empty()){
        string current = st.back();
        if(route[current].size()==0){
            answer.push_back(current);
            st.pop_back();
        }else{
            st.push_back(route[current].back());
            route[current].pop_back();
        }
    }
    reverse(answer.begin(), answer.end());
    
//    string next = "ICN";
//    answer.push_back(next);
//    while(route[next].size()>0){
//
//        string temp = next;
//        next = route[temp].back();
//        answer.push_back(next);
//        route[temp].pop_back();
//
//    }
    return answer;
}

void assertion(vector<vector<string>> input, vector<string> output ){
    vector<string> t = solution(input);
    if(t!=output){
        cout<< "wrong answer\n";
    }else{
        cout<< "Correct!\n";
    }
}

int main(){
    
    assertion({{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}}, {"ICN", "JFK", "HND", "IAD"});
    assertion({{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"},{"ATL", "ICN"},{"ATL", "SFO"}}, {"ICN", "ATL","ICN", "SFO", "ATL", "SFO"});
    return 0;
}
