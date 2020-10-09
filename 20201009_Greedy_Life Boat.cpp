// 프로그래머스 > 코딩테스트 연습 > 탐욕법 > 구명보트
//  20201009_Greedy_Life Boat.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 10/9/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer=0;
    sort(people.begin(), people.end());
    int head = 0;
    int tail = people.size()-1;
    while (head<tail) {
        if(people[head]+people[tail]<=limit)
            head++;
        tail--;
        answer++;
        if(head==tail)
            answer++;
    }
    return answer;
}

void assertions(vector<int> people, int limit, int result){
    int answer = solution(people, limit);
    if(answer == result){
        cout << "Correct Answer \n";
    }else{
        cout << "Wrong Answer \n";
    }
    cout << answer <<"\n";
}

int main(){
    assertions({70,50,80,50}, 100, 3);
    assertions({70,80,50}, 100, 3);
    assertions({20,30,40,50,80}, 100, 3);
    return 0;
}
