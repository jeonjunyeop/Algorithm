// 프로그래머스_네트워크
//  20200623_DFS_Network.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 6/23/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool visited[200];

void dfs(int p, vector<vector<int>> computers){
    visited[p]=1;
    for(int i=0; i<computers.size(); i++){
        if(computers[p][i]==1 && p!=i && visited[i]==0){
            dfs(i, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0; i<computers.size(); i++){
        if(visited[i]==0){
            dfs(i, computers);
            answer++;
        }
    }
    return answer;
}

void assertion(int n, vector<vector<int>> computers, int inresult){
    int answer = solution(n,  computers);
    if(answer == inresult){
        cout << "Correct answer.\n";
        cout << answer<<"\n";
    }else{
        cout << "Wrong answer.\n";
        cout << answer<<"\n";
    }
    memset(visited, 0, sizeof(visited));
}
int main(){
    assertion(3, {{1,1,0},{1,1,0},{0,0,1}},2);
    assertion(3, {{1,1,0},{1,1,1},{0,1,1}},1);
   
    
    return 0;
}
