// 백준14891 톱니바퀴
//  20200417_SIM_Cogwheel.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 4/17/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <deque>
#include <queue>
using namespace std;
deque<int> first;
deque<int> second;
deque<int> third;
deque<int> fourth;
queue<pair<pair<int, int>,int>> q;
int K;

void rotation(deque<int> &dq, int direction){
    if(dq.size()){
    if(direction==1){
        int tail =dq.back();
        dq.pop_back();
        dq.push_front(tail);
    }else{
        int head = dq.front();
        dq.pop_front();
        dq.push_back(head);
    }
    }
}

void bfs(int num, int dir){
    //cout <<"bfs\n";
    q.push(make_pair(make_pair(num, dir), 0));
    while (!q.empty()) {
        int wheel_number = q.front().first.first;
        int direction = q.front().first.second;
        int previous_number = q.front().second;
        q.pop();
        //cout << wheel_number<<" , " << direction <<" , "<< previous_number<<"\n";
        if(wheel_number==1){
            bool right_wheel=0;
            if(first[2]!=second[6])
                right_wheel=1;
            rotation(first, direction);
            if(right_wheel && previous_number!=2){
                q.push(make_pair(make_pair(2, -direction),wheel_number));
            }
        }
        else if(wheel_number==2){
            bool right_wheel = 0;
            bool left_wheel = 0;
            if(second[2]!=third[6])
                right_wheel = 1;
            if(second[6]!=first[2])
                left_wheel = 1;
            rotation(second, direction);
            if(right_wheel && previous_number!=3){
                q.push(make_pair(make_pair(3, -direction),wheel_number));
            }
            if(left_wheel && previous_number!=1){
                q.push(make_pair(make_pair(1, -direction),wheel_number));
            }
        }
        else if(wheel_number==3){
            bool right_wheel = 0;
            bool left_wheel = 0;
            if(third[2]!=fourth[6])
                right_wheel=1;
            if(third[6]!=second[2])
                left_wheel=1;
            rotation(third, direction);
            if(right_wheel && previous_number!=4){
                q.push(make_pair(make_pair(4, -direction),wheel_number));
            }
            if(left_wheel && previous_number!=2){
                q.push(make_pair(make_pair(2, -direction),wheel_number));
            }
        }
        else if(wheel_number==4){
            bool left_wheel = 0;
            if(fourth[6]!=third[2])
                left_wheel=1;
            rotation(fourth, direction);
            if(left_wheel && previous_number!= 3){
                q.push(make_pair(make_pair(3, -direction),wheel_number));
            }
        }
    }
}

int main(){
    int temp;
    for(int i=0; i<8; i++){
        scanf("%1d",&temp);
        first.push_back(temp);
    }
    for(int i=0; i<8; i++){
        scanf("%1d",&temp);
        second.push_back(temp);
    }
    for(int i=0; i<8; i++){
        scanf("%1d",&temp);
        third.push_back(temp);
    }
    for(int i=0; i<8; i++){
        scanf("%1d",&temp);
        fourth.push_back(temp);
    }
    cin >>K;
    int a,b;
    for(int i=0; i<K; i++){
        cin >> a >> b;
        bfs(a,b);
    }
    int score=0;
    if(first[0]==1)
        score+=1;
    if(second[0]==1)
        score+=2;
    if(third[0]==1)
        score+=4;
    if(fourth[0]==1)
        score+=8;
    cout << score;
    return 0;
}

