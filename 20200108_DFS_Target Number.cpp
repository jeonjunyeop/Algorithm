// 타겟 넘버 _ 프로그래머스
//  20200108_DFS_Target Number.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 1/8/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int answer = 0;

void dfs(vector<int> numbers, int sum, int target, int count){
    
    int size = numbers.size();
    if(count==size){
        if(sum==target)
            answer++;
        return;
    }
    dfs(numbers, sum+numbers[count], target, count+1);
    dfs(numbers, sum-numbers[count], target, count+1);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers,0,target,0);
    return answer;
}

void assertions(vector<int> numbers, int target, int answer){
    int t = solution(numbers, target);
    if(t==answer)
        cout <<"Correct!"<<endl;
    else
        cout <<"Wrong!"<<" "<<t<<endl;
}

int main(){
    assertions({1,1,1,1,1}, 3, 5);
    
    return 0;;
}

