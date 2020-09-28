// 프로그래머스 _ 그래프 _ 가장 먼 노드
//  20200928_Dijkstra_FarthestNode.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 9/28/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;
int MAX = 987654321;
int dijkstra(int start, int n, unordered_set<int>s[]){
    int answer =0;
    priority_queue<pair<int, int>>pq;
    vector<int> dist(n+1, MAX);
    dist[0]=0;
    pq.push({0,1});
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int location = pq.top().second;
        pq.pop();
        
        if(cost < dist[location]){
            dist[location] = cost;
            for(auto & x : s[location])
                pq.push({-(cost+1), x });
        }
    }
    int max_val=0;
    for(auto & x : dist)
        if(x>max_val)
            max_val = x;
    
    for(auto& x : dist)
        if(x==max_val)
            answer++;
    
    return answer;
}
int solution(int n, vector<vector<int>> edge) {
    int len = edge.size();
    unordered_set<int> s[n+1];
    for(int i=0; i<len; i++){
        int a = edge[i][0];
        int b = edge[i][1];
        s[a].insert(b);
        s[b].insert(a);
    }
    return dijkstra(1, n, s);
}

void assertions(int n, vector<vector<int>> vertex, int result){
    int answer = solution(n,vertex);
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
    assertions(6,{{3,6},{4,3},{3,2},{1,3},{1,2},{2,4},{5,2}},3);
    
    return 0;
}
