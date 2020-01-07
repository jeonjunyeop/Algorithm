// 숨바꼭질 _ 백준1697
//  20200107_BFS_Hide&seek.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 1/7/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <queue>
using namespace std;
int n, k;
int visited[100001];

int bfs(int idx){
    int cnt=0;
    queue<int> q;
    q.push(idx);
    visited[idx]=1;
    while (1) {
        int size = q.size();
        
        for(int i=0; i<size; i++){
            
            int current = q.front();
           
            if(current==k)
                return cnt;
            q.pop();
            
            int plus = current+1;
            int minus = current-1;
            int multi = current*2;
            if(plus<=100000 && !visited[plus]){
                q.push(plus);
                visited[plus]=1;
            }
            if(multi<=100000 && !visited[multi]){
                q.push(multi);
               visited[multi]=1;
            }
            if(minus>=0 && !visited[minus]){
                q.push(minus);
                visited[minus]=1;
            }
        }cnt++;
    }
}

int main(){
    cin >> n>>k;
    cout << bfs(n);
    return 0;
}
