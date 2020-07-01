// 예산 _ 프로그래머스 _ 이분탐색
//  20200701_B Search_Budget.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 7/1/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int total_value(vector<int> v, int up_limit){
    int sum=0;
    for(auto & x : v){
        if(x>up_limit){
            sum += up_limit;
        }else{
            sum+=x;
        }
    }
    return sum;
}

int solution(vector<int> budgets, int M) {
    int start = 0;
    int mid = M;
    int end = M;
    int prev_mid=0;
    int maxv = 0;
    for(auto & x : budgets){
        maxv = max(maxv, x);
    }
    if(total_value(budgets, M)<=M)
        return maxv;
    while(1){
            mid = (start+end)/2;
            
            if(prev_mid==mid){
                return mid;
            }
            
            if(total_value(budgets, mid)>M){
                end = mid;
            }else if(total_value(budgets, mid)<M){
                start = mid;
            }else{
                return mid;
            }
            prev_mid = mid;
    }
    
    return mid;
}

void assertion(vector<int>budgets, int M ,int inreturn){
    int answer = solution(budgets, M);
    if(answer ==inreturn){
        cout << "Correct!\n";
    }else{
        cout << "Unfortunately, you put the wrong answer.\n";
        cout << answer<<"\n";
    }
}

int main(){
    
    assertion({120,110,140,150},485, 127);
    assertion({1,2,3,4,5,6,7,8,9,10},56, 10);

    return 0;
}
