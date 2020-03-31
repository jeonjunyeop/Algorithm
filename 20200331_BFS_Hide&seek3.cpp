//  BFS 숨바꼭질3 백준13549
//  20200331_BFS_Hide&seek3.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 3/31/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N,K;
int time_table[100001];
queue<int> q;
int bfs(){
    time_table[N]=0;
 
    while (!q.empty()) {
        int current =  q.front();
        q.pop();
        if(current==K){
            return time_table[current];
        }
        int nextnum;
        
        nextnum = current - 1;
        if(0<=nextnum && time_table[nextnum]>time_table[current]+1){
            time_table[nextnum] = min(time_table[nextnum] ,time_table[current]+1);
            q.push(nextnum);
        }
        nextnum = current + 1;
        if(nextnum<=100000 && time_table[nextnum]>time_table[current]+1){
            time_table[nextnum] = min(time_table[nextnum] ,time_table[current]+1);
            q.push(nextnum);
        }
        nextnum = current * 2;
        if(nextnum<=100000 && time_table[nextnum]>time_table[current]){
            time_table[nextnum] = min(time_table[nextnum] ,time_table[current]);
            q.push(nextnum);
        }
    }
    return 0;
}

void initialization(){
    for(int i=0; i<=100000; i++)
        time_table[i] = 987654321;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N>>K;
    q.push(N);
    initialization();
    cout << bfs();
    return 0;
}
