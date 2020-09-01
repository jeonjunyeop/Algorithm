// Programmers 체육복
//  20200901_Greedy_Gym suit.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 9/1/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    bool visited[31]={0,};
    unordered_map<int, int> m;
    for(int i=1; i<=n; i++){
        m[i]++;
    }
    for(int i=0;i <lost.size(); i++){
        m[lost[i]]--;
    }
    for(int i=0; i<reserve.size(); i++){
        m[reserve[i]]++;
    }

//    for(auto& x : m){
//        cout << x.first <<","<< x.second <<"\n";
//    }
//    cout <<"\n";
    for(int i=1; i<=n; i++){
        //Left
        if(visited[i]==0 && m[i]==2){
            if(visited[i-1]==0 && i>1 && m[i-1] == 0){
                m[i]--;
                m[i-1]++;
                visited[i] = 1;
                visited[i-1] = 1;
            }else if(visited[i+1]==0 && i+1<=n &&m[i+1]==0){
                m[i]--;
                m[i+1]++;
                visited[i] = 1;
                visited[i+1] = 1;
            }
        }
    }
    for(auto & i : m){
        if(i.first>0 && i.first<=n && (i.second==2 || i.second==1))
            answer ++;
    }
//    for(auto& x : m){
//        cout << x.first <<","<< x.second <<"\n";
//    }
//    cout <<"\n";
//    cout <<"\n";
   

    return answer;
}

void assertions(int n, vector<int>lost ,vector<int> reserve, int result){
    int answer = solution(n, lost, reserve);
    if( answer == result){
        cout << "Correct answer \n";
    }else{
        cout << "Wrong answer \n";
        cout <<answer<<"\n";
    }
    cout << "\n";
    reserve.clear();
    lost.clear();
}

int main(){
    assertions(5, {2,4}, {1,3,5}, 5);
    assertions(5, {2,4}, {3}, 4);
    assertions(3, {3}, {1}, 2);
    return 0;
}
