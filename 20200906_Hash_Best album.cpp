// 프로그래머스 > 해시 > 베스트앨범
//  20200906_Hash_Best album.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 9/6/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool cmp (const pair<int, int> &a, const pair<int, int> &b){
    if(a.first>b.first){
        return true;
    }else if(a.first<b.first){
        return false;
    }else{
        if(a.second>b.second){
            return false;
        }else{
            return true;
        }
    }
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> m;
    
    // To find the most played genre
    for(int i=0; i<genres.size(); i++){
        m[genres[i]] += plays[i];
    }
    vector<pair<int, string>> rank;
    for(auto & x : m){
        rank.push_back({x.second,x.first});
    }
    sort(rank.begin(), rank.end(), greater<pair<int, string>>());
    
    
    for(int i=0;i <rank.size(); i++){
        string gen = rank[i].second;
        vector<pair<int, int>> v;
        for(int j=0; j<genres.size(); j++){
            if(gen==genres[j]){
                v.push_back({plays[j] ,j});
            }
        }
        sort(v.begin(), v.end(),cmp);
        answer.push_back(v[0].second);
        if(v.size()>1)
            answer.push_back(v[1].second);
    }
    
    return answer;
}

void assertions(vector<string> gen, vector<int> p, vector<int> result){
    vector<int> answer = solution(gen, p);
    if(answer == result){
        cout << "Correct answer \n";
    }else{
        cout << "Wrong answer \n";
    }
    
    for(auto& x : answer){
        cout << x << " ";
    }cout <<"\n";
}

int main(){
    
    assertions({"classic", "pop", "classic","classic", "pop"},{500, 600, 150, 800, 2500},{4,1,3,0});
    
    return 0;
}
