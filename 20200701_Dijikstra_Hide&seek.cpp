//
//  20200701_Dijikstra_Hide&seek.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 7/1/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
/*Bessie is playing hide and seek (a game in which a number of players hide and a single player (the seeker) attempts to find them after which various penalties and rewards are assessed; much fun usually ensues).

She is trying to figure out in which of N (2 <= N <= 20,000) barns conveniently numbered 1..N she should hide. She knows that FJ (the seeker) starts out in barn 1. All the barns are connected by M (1 <= M <= 50,000) bidirectional paths with endpoints A_i and B_i (1 <= A_i <= N; 1 <= B_i <= N; A_i != B_i); it is possible to reach any barn from any other through the paths.

Bessie decides that it will be safest to hide in the barn that has the greatest distance from barn 1 (the distance between two barns is the smallest number of paths that one must traverse to get from one to the other). Help Bessie figure out the best barn in which to hide.

INPUT
Line 1: Two space-separated integers: N and M
Lines 2..M+1: Line i+1 contains the endpoints for path i: A_i and B_i
 
OUTPUT
Line 1: On a single line, print three space-separated integers: the index of the barn farthest from barn 1 (if there are multiple such barns, print the smallest such index), the smallest number of paths needed to reach this barn from barn 1, and the number of barns with this number of paths.*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>

using namespace std;

int n,m;

void dijkstra(unordered_set<int> s []){
    vector<int> dist(n+1,987654321);
    dist[1] = 0;
    priority_queue<pair<int, int>>pq;
    pq.push({0,1});
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int location = pq.top().second;
        pq.pop();
        if(cost>dist[location])
            continue;
        for(auto& x : s[location]){
            int next_loc = x;
            int next_cost = dist[location] + 1;
            if(dist[next_loc] > next_cost){
                dist[next_loc] = next_cost;
                pq.push({-next_cost, next_loc});
            }
            
        }
    }
    
    int maxv = 0;
   
    vector<pair<int, int>> v;
    for(int i=0; i<dist.size(); i++){
        if(dist[i]!=987654321){
            maxv = max(maxv, dist[i]);
        }
    }
    for(int i=0; i<dist.size(); i++){
        if(dist[i]==maxv){
            v.push_back({i,dist[i]});
        }
    }
    cout << v[0].first <<" "<<maxv<<" "<<v.size()<<"\n";
    
//    for(int i=0; i<dist.size(); i++){
//        cout << dist[i]<<" ";
//    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n >> m;
    unordered_set<int> s[n+1];
    int a,b;
    for(int i=0; i<m; i++){
        cin >> a>> b;
        s[a].insert(b);
        s[b].insert(a);
    }
    dijkstra(s);
    return 0;
}
