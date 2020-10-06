// 프로그래머스 _ 섬 연결하기
//  20201006_Union-Find_Connect Islands.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 10/6/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find_parent(int a, int table[]){
    if(table[a] == a) return a;
    else return table[a] = find_parent(table[a], table);
}

void union_parent(int a, int b, int table[]){
    a = find_parent(a, table);
    b = find_parent(b, table);
    if(a<b)
        table[b] = a;
    else if(a>b)
        table[a] = b;
}

bool compare_parent(int a , int b , int table[]){
    a = find_parent(a, table);
    b = find_parent(b, table);
    if(a==b) return 1;
    else return 0;
}

void initialization(int table[], int n){
    for(int i=0; i<n; i++){
        table[i] = i;
    }
}

bool comp(pair<pair<int, int>, int> const &a, pair<pair<int, int>, int> const &b){
    if(a.second<b.second)
        return true;
    else
        return false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int table[100];
    initialization(table, n);
    vector<pair<pair<int, int>, int>> v;
    for(int i=0; i<costs.size(); i++){
        v. push_back({{costs[i][0],costs[i][1]},costs[i][2]});
    }
    sort(v.begin(), v.end(), comp);
    
    for(int i=0; i<v.size(); i++){
        int a = v[i].first.first;
        int b = v[i].first.second;
        int value = v[i].second;
        if(compare_parent(a, b, table)==0){
            union_parent(a, b, table);
            answer += value;
        }
    }
    
    
    return answer;
}

void assertions(int n, vector<vector<int>> costs, int result){
    int answer = solution(n, costs);
    if(answer==result){
        cout << "Correct!\n";
    }else{
        cout << "Wrong @@\n";
    }
    cout << answer<<"\n";
}

int main(){

    assertions(4, {{0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8}}, 4);

    return 0;
}
