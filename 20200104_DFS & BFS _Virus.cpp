//  Virus 바이러스_ 백준 2606
//  20200104_DFS & BFS _Virus.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 1/4/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

bool route[101][101];
bool visited[101];
queue<int> q;
int n,l,cnt,count;

void dfs(int idx){
    for(int i=1; i<=n; i++){
        if(route[idx][i]&&!visited[i]){
            visited[i]=1;
            cnt++;
            dfs(i);
        }
    }
}

void bfs(int idx){
    q.push(idx);
    visited[idx]=1;
    while(!q.empty()){
        idx=q.front();
        q.pop();
        for(int i=1; i<=n; i++){
            if(route[idx][i]&&!visited[i]){
                q.push(i);
                visited[i]=1;
                cnt++;
            }
        }
    }
}

int main(){
    cin >> n >>l;
    for(int i=0; i<l; i++){
        int from, to;
        cin >>from >> to;
        route[from][to] = route[to][from] = 1;
    }
    //visited[1]=1;
    //dfs(1);
    bfs(1);
    cout << cnt;
        return 0;
}
