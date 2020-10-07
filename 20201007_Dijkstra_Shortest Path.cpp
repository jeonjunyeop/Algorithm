// 백준1753 최단경로
//  20201007_Dijkstra_Shortest Path.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 10/7/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

unordered_map<int, vector<pair<int, int>>> m;

void dijkstra(int initial_vertex, int num){
    vector<int> dist(num+1, 987654321);
    dist[initial_vertex] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, initial_vertex});
    while (!pq.empty()) {
        int distance = -pq.top().first;
        int location = pq.top().second;
        pq.pop();
        
        for(auto& x : m[location]){
            int next_location = x.first;
            int next_distance = x.second + distance;
            if(next_distance<dist[next_location]){
                dist[next_location] = next_distance;
                pq.push({-next_distance,next_location});
            }
        }m[location].clear();
    }
    for(int i=1; i<=num; i++){
        if(dist[i]==987654321)
            cout << "INF\n";
        else
            cout << dist[i] <<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int V, E; //
    int start;
    cin >> V >> E >> start;
    int u,v,w;
    
    for(int i=0; i<E; i++){
        cin >> u >> v >> w;
        m[u].push_back({v,w});
    }
    
    dijkstra(start, V);
    
    return 0;
}
