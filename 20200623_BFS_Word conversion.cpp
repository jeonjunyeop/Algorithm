// 프로그래머스_단어변환
//  20200623_BFS_Word conversion.cpp
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
#include <queue>

using namespace std;

bool visited[50];

bool cmp(string a, string b){
    int num=a.size();
    for(int i=0; i<a.size(); i++){
        if(a[i] != b[i]){
            num--;
        }
    }
    if(a.size()-num > 1){
        return false;
    }else{
        return true;
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<pair<string, int>> q;
    q.push({begin,0});
    while (!q.empty()) {
        string current = q.front().first;
        int num = q.front().second;
        q.pop();
        
        if(current == target){
            answer = num;
            break;
        }
        
        for(int i=0; i<words.size(); i++){
            if(visited[i]==0 && cmp(current, words[i]) && num<words.size()){
                q.push({words[i], num+1});
            }
        }
    }
    
    return answer;
}

void assertion(string begin, string target, vector<string> words, int inresult){
    int answer = solution(begin, target, words);
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
    assertion("hit", "cog", {"hot","dot","dog","lot","log","cog"}, 4);
    assertion("hit", "cog", {"hot","dot","dog","lot","log"}, 0);
   
    
    return 0;
}
