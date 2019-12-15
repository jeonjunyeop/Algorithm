//
//  20191215_Greedy_MeetingSchedule(Korean).cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 12/14/19.
//  Copyright © 2019 Junyeop Jeon. All rights reserved.
////
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int answer = 0;
    int N;
    int starting[100000], ending[100000];
    vector<pair<int, int>> v;
    
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> starting[i];
        cin >> ending[i];
        v.push_back(make_pair(ending[i], starting[i]));
    }
    sort(v.begin(),v.end());
    
    int endPoint = 0;
    
    for(int j=0; j<N; j++){
        if(endPoint<=v[j].second){
            endPoint=v[j].first;
            answer++;
        }
    }
    cout<< answer;
    return 0;
}
