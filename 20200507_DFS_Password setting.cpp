// 암호 만들기 백준1759
//  20200507_DFS_Password setting.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 5/7/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n,m;
vector<char> candidates;
vector<char> v;
void dfs(int idx){
    if(idx>candidates.size()){
        return;
    }
    if(v.size()==n){
        int vowel=0;
        int consonant=0;
        for(auto& x : v){
            if( x=='a' || x=='e' || x=='i' || x=='o' || x=='u')
                vowel++;
            else
                consonant++;
        }
        if(consonant<2 || vowel<1)
            return;
        
        //print
        for(auto& x : v){
            cout << x;
        }cout <<"\n";
        return;
    }
    v.push_back(candidates[idx]);
    dfs(idx+1);
    v.pop_back();
    dfs(idx+1);
}

int main(){
    cin >> n >> m;
    char temp;
    for(int i=0 ;i<m; i++){
        cin >> temp;
        candidates.push_back(temp);
    }
    sort(candidates.begin(), candidates.end());
    dfs(0);
    //cout << "end\n";
    return 0;
}
