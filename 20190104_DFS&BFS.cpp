// DFS 와 BFS _ 백준 1260
//  20190104_DFS&BFS.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 1/4/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

queue<int> q;
int route[1001][1001];
bool visited[1001];
int n,m,v;

void dfs(int idx){
    cout<<idx<<" ";
    
    for(int i=1; i<=n; i++){
        if(route[idx][i]&&!visited[i]){
            visited[i]=1;
            dfs(i);
        }
    }
}
void bfs(int idx){
    q.push(idx);
    visited[idx]=1;
    
    while(!q.empty()){
        idx = q.front();
        q.pop();
        cout << idx<<" ";
        
        for(int i=1; i<=n; i++){
            if(route[idx][i]&&!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}
int main(){
    cin >> n>> m>>v;
    for(int i=0; i<m; i++){
        int from,to;
        cin>> from >> to;
        route[from][to] = 1;
        route[to][from] = 1;
    }
    
    visited[v]=1;
    dfs(v);
    cout <<endl;
    memset(visited, false, sizeof(visited));
    bfs(v);
        return 0;
}
