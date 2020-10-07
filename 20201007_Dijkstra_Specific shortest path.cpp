// 백준1504 특정한 최단 경로
//  20201007_Dijkstra_Specific shortest path.cpp
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
// 1 -> v1 -> v2 -> N
unordered_map<int, vector<pair<int, int>>> m;
int N,E;
int INF = 987654321;

int dijkstra(int source, int destination){
    int answer = 0;
    vector<int> dist(N+1, INF);
    dist[source] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0,source});
  
    while (!pq.empty()) {
        int distance = -pq.top().first;
        int location = pq.top().second;
        pq.pop();
        
        for(auto & i : m[location]){
            int next_distance = distance + i.second;
            int next_location = i.first;
            
            if(next_distance<dist[next_location]){
                dist[next_location] = next_distance;
                pq.push({-next_distance,next_location});
            }
        }
    }
    return dist[destination];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int v1, v2, result;
    cin >> N >> E;
    int a, b, c;
    for(int i=0; i<E; i++){
        cin >> a >> b >> c;
        //Two-ways
        m[a].push_back({b,c});
        m[b].push_back({a,c});
    }
    cin >> v1 >> v2;
    
    result = min(dijkstra(1, v1) + dijkstra(v2, N), dijkstra(1, v2) + dijkstra(v1, N));
    if(result==INF || dijkstra(v1, v2) == INF){ // If you cannot visit v1 and v2.
        cout << "-1\n";
        return 0;
    }
    cout << result + dijkstra(v1, v2)<<"\n";

    return 0;
}
