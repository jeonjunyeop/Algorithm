//
//  20201027_Dijkstra_MinimumCost.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 10/27/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//

// 백준1916 최소비용 구하기 Minimum cost
// 다익스트라 알고리즘 리뷰 Dijkstra Algorithm REVIEW
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

int INF = 987654321;
unordered_map<int, vector<pair<int, int>>>edge;

int dijkstra(int source, int destination, int n){
    int minimum_cost = 0;
    vector<int> dist(n+1, INF);
    dist[source] = 0;
    priority_queue<pair<int, int>>pq;
    pq.push({0,source});
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int current = pq.top().second;
        pq.pop();
        
        if(dist[current]<cost)
            continue;
        else if(dist[current]>cost)
            dist[current] = cost;
        
        for(auto & i : edge[current])
            pq.push({-cost-i.second,i.first});
    }
    /*for(int i=0; i<=n; i++) // PRINT
        cout <<i <<": "<<dist[i] <<"\n";*/
    
    return dist[destination];
}

int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
 
    int from, to, cost;
    for(int i=0; i<m; i++){ // READ EDGES
        cin >> from >> to >> cost;
        edge[from].push_back({to,cost});
    }
    int a, b;
    cin >> a >> b;
    cout << dijkstra(a, b, n)<<"\n"; // MINIMUM COST A TO B
    
    return 0;
}
