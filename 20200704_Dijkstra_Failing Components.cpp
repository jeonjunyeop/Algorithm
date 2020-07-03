//ICPC > Regionals > Europe > Northwestern European Regional Contest > Benelux Algorithm Programming Contest > BAPC 2014 Preliminaries B
// 백준 10282 해킹
//  20200704_Dijkstra_Failing Components.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 7/4/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
/*As a jury member of the Best Architectural Planning Contest, you are tasked with scoring the reliability of a system. All systems entered in the contest consist of a number of components which depend on each other. The reliability of such a system depends on the damage done by a failing component. Ideally a failing component should have no consequences, but since most components depend on each other, some other components will usually fail as well.

Most components are somewhat resilient to short failures of the components they depend on. For example, a database could be unavailable for a minute before the caches expire and new data must be retrieved from the database. In this case, the caches can survive for a minute after a database failure, before failing themselves. If a component depends on multiple other components which fail, it will fail as soon as it can no longer survive the failure of at least one of the components it depends on. Furthermore no component depends on itself directly, however indirect self-dependency through other components is possible.

You want to know how many components will fail when a certain component fails, and how much time passes before all components that will eventually fail, actually fail. This is difficult to calculate by hand, so you decided to write a program to help you. Given the description of the system, and the initial component that fails, the program should report how many components will fail in total, and how much time passes before all those components have actually failed.

INPUT
On the first line one positive number: the number of test cases, at most 100. After that per test case:

one line with three space-separated integers n, d and c (1 ≤ n ≤ 10 000 and 1 ≤ d ≤ 100 000 and 1 ≤ c ≤ n): the total number of components in the system, the number of dependencies between components, and the initial component that fails, respectively.
d lines with three space-separated integers a, b and s (1 ≤ a, b ≤ n and a ≠ b and 0 ≤ s ≤ 1 000), indicating that component a depends on component b, and can survive for s seconds when component b fails.
In each test case, all dependencies (a, b) are unique.

OUTPUT
Per test case:

one line with two space-separated integers: the total number of components that will fail, and the number of seconds before all components that will fail, have actually failed.*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int n,d,c;

void dijkstra(vector<pair<int, int>>v[]){
    priority_queue<pair<int, int>> pq;
    pq.push({0, c});
    vector<int>dist(n+1,987654321);
    dist[c]=0;
    while (!pq.empty()) {
        int location = pq.top().second;
        int value = -pq.top().first;
        pq.pop();
        if(dist[location]<value)
            continue;
        for(int i=0; i<v[location].size(); i++){
            int next_location = v[location][i].second;
            int next_value = v[location][i].first + value;
            if(dist[next_location]>next_value){
                dist[next_location] = next_value;
                pq.push({-next_value,next_location});
            }
        }
    }
    int cnt=0;
    int maxv=0;
    for(auto & x : dist){
        if(x!=987654321){
            cnt++;
            maxv = max(maxv, x);
        }
    }
    cout << cnt <<" "<<maxv<<"\n";
}

int main(){
    int t,a,b,s;
    cin >> t;
    while (t--) {
        cin >> n >> d >> c;
        vector<pair<int, int>> v[10001];
        for(int i=0; i<d; i++){
            cin >> a >> b >> s;
            v[b].push_back({s,a});
        }
        dijkstra(v);
    }
    return 0;
}
