//
//  20201008_Dijkstra_Destination Unknown.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 10/8/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
// 백준 9370 미확인 도착지

/* ICPC > Regionals > Europe > Northwestern European Regional Contest > Benelux Algorithm Programming Contest > BAPC 2013 D
 Destination Unknown */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
// Return the possible candidates. s ->  g->h -> candidates
int INF = 987654321;
unordered_map<int, vector<pair<int, int>>> table;

int dijkstra(int n, int source ,int destination){
    
    vector<int>dist(n+1, INF);
    dist[source] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0,source});
    while (!pq.empty()) {
        int location = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        
        for(auto& x : table[location]){
            int next_cost = cost + x.second;
            int next_loc = x.first;
            if(next_cost<dist[next_loc]){
                pq.push({-next_cost,next_loc});
                dist[next_loc] = next_cost;
            }
        }
        
    }
    return dist[destination];
}

bool possibility(int n, int source, int stop1, int stop2, int destination, int g2h){
    // (s -> stop1 -> stop2 -> d) || (s -> stop2 -> stop1 -> d)
    int min_cost = dijkstra(n, source, destination);
    int scenario1 = dijkstra(n, source, stop1) + g2h + dijkstra(n, stop2, destination);
    int scenario2 = dijkstra(n, source, stop2) + g2h + dijkstra(n, stop1, destination);
    
    if(min_cost == scenario1 || min_cost == scenario2){
        return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test_case;
    cin >> test_case;
    while (test_case--) {
        int n, m, t; // Number of Vertex, Path, Candidate
        cin >> n >> m >> t;
        int s, g, h; // Source, stop1, stop2
        cin >> s >> g >> h;
        
        // Read Path and cost
        int a, b, d; // Path a->b, cost:d
        int g2h=0;
        table.clear(); // Clear the hash
        for(int i=0; i<m; i++){
            cin >> a >> b >> d;
            table[a].push_back({b,d});
            table[b].push_back({a,d});
            if((a==g && b==h) || (a==h && b==g))
                g2h = d;
        }
        // Read candidates
        vector<int> candidate;
        int temp;
        for(int i=0; i<t; i++){
            cin >>temp;
            candidate.push_back(temp);
        }
        vector<int> answer;
        for(auto& x : candidate){
            if(possibility(n,s,g,h,x,g2h)==true){
                answer.push_back(x);
            }
        }
        //Print answer
        sort(answer.begin(), answer.end());
        for(auto &x : answer)
            cout << x <<" ";
        cout <<"\n";
    }
    return 0;
}
