// 백준14889스타트와링크
//  20200415_Brute-force_Start&Link.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 4/15/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
bool individual[21];
int table[21][21];
int N,team1_score, team2_score, gap=987654321;

bool halfandhalf_confirmed(){
    int cnt=0;
    for(int i=1; i<=N; i++)
        if(individual[i]==1)
            cnt++;
    if(cnt==N/2)
        return true;
    return false;
}

void dfs(int idx){
    if(halfandhalf_confirmed()){
//        for(int i=1; i<=N; i++)
//            if(individual[i]==1)
//                cout << i<<" ";
//        cout <<"\n";
        for(int i=1; i<=N; i++){
            for(int j=i+1; j<=N; j++){
                if(individual[i]&&individual[j]){
                    team1_score+=table[i][j];
                    team1_score+=table[j][i];
                }else if(!individual[i]&&!individual[j]){
                    team2_score+=table[i][j];
                    team2_score+=table[j][i];
                }
            }
        }
        gap = min(gap, abs(team1_score-team2_score));
//        cout << "team1:"<<team1_score<<" team2:"<<team2_score<<"\n";
//        cout << gap<<"\n";
        team1_score = team2_score = 0;
        return;
    }
    if(idx>N){
        return;
    }
    
    individual[idx]=1;
    dfs(idx+1);
    individual[idx]=0;
    dfs(idx+1);
}

int main(){
    cin >> N;
    for(int i=1 ;i<=N; i++)
        for(int j=1; j<=N; j++)
            cin >> table[i][j];
    
    individual[1]=1;
    dfs(2);
    cout << gap;
    return 0;
}
