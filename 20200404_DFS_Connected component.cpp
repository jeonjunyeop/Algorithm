// 백준11724 연결 요소의 개수
//  20200404_DFS_Connected component.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 4/4/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int N,M,cnt;
bool visited[1001];
unordered_map<int , vector<int>> m;
void dfs(int point){
    
    if(m[point].size()==0)
        return;
    
    while(m[point].size()>0){
        int next_point = m[point].back();
        m[point].pop_back();
        
        if(visited[next_point]==0){
            visited[next_point]=1;
            dfs(next_point);
        }
    }
}
void solution(){
    for(int i=1; i<=N; i++){
        if(visited[i]==0){
            visited[i]=1;
            dfs(i);
            cnt++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N>>M;
    int a,b;
    for(int i=0; i<M; i++){
        cin >>a>>b;
        m[a].push_back(b);
        m[b].push_back(a);
    }
    solution();
    cout <<cnt;
    return 0;
}
