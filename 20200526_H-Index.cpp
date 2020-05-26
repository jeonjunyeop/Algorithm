// 프로그래머스 정렬 H-Index
//  20200526_H-Index.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 5/26/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    bool done = false;
    sort(citations.begin(), citations.end(), greater<int>());
    for(int i=0; i<citations.size(); i++){
        if(citations[i]<i+1){
            answer=i;
            break;
        }
        if(i==citations.size()-1)
            done = true;
    }
    if(answer==0 && done==true)
        answer = citations.size();
    return answer;
}

void assertion(vector<int> incitations, int inreturn){
    int answer = solution(incitations);
    if(answer == inreturn){
        cout << "Correct answer.\n";
       
    }else{
        cout << "Wrong answer.\n";
       // cout << answer<<"\n";
    }
}
int main(){
    assertion({3,0,6,1,5},3);
    assertion({10,8,5,4,3},4);
    assertion({25,8,5,3,3},3);
    assertion({20,19,18,1},3);
    assertion({20,19,18,17},4);
    assertion({0,0,0,0,0},0);
   
    return 0;
}
