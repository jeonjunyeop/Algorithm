// 프로그래머스 타겟넘버
//  20200603_DFS_Target number.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 6/3/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
int num = 0;

void dfs(vector<int> v, int idx, int total, int target){
    if(idx==v.size()){
        if(total == target)
            num++;
        return;
    }
    dfs(v, idx+1, total+v[idx] , target);
    dfs(v, idx+1, total-v[idx] , target);
}

int solution(vector<int> numbers, int target) {
    int result = 0;
    dfs(numbers, 0, 0, target);
    result = num;
    
    return result;
}

void assertion(vector<int> innumbers, int intarget, int inreturn){
    int answer = solution(innumbers, intarget);
    if(answer == inreturn){
        cout << "Correct answer.\n";
    }else{
        cout << "Wrong answer.\n";
    }
}
int main(){
    assertion({1,1,1,1,1},3 ,5);

    return 0;
}
