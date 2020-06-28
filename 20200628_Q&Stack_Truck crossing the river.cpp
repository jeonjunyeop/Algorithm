//
//  20200628_Q&Stack_Truck crossing the river.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 6/28/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    vector<int> arrived;
    queue<pair<int,int>> bridge;
    int capacity=0;
    
    capacity += truck_weights[0];
    bridge.push({truck_weights[0],1}); //The first truck is pushed to the q.
    truck_weights.erase(truck_weights.begin()); //Deleted from the vector.
     
    while(!bridge.empty()){
        answer++; // Elapsed time
    
        //Arrived
        if(bridge.size()!=0 && bridge.front().second+bridge_length == answer){
            int next = bridge.front().first;
            arrived.push_back(next);
            capacity -= next;
            bridge.pop();
            
        }

        //Enter to the bridge
        if(truck_weights.size()!=0 && capacity + truck_weights[0]<=weight){
            bridge.push({truck_weights[0],answer});
            capacity += truck_weights[0];
            truck_weights.erase(truck_weights.begin());
        }
    }
    return answer;
}

void assertion(int bridge_length, int weight, vector<int> truck_weights, int inresult){
    int answer = solution(bridge_length, weight, truck_weights);
    if(answer == inresult){
        cout << "Correct answer.\n";
    }else{
        cout << "Wrong answer.\n";
    }
}
int main(){
    assertion(2, 10, {7,4,5,6}, 8);
    assertion(100, 100, {10}, 101);
    assertion(100, 100, {10,10,10,10,10,10,10,10,10,10}, 110);
     
    return 0;
}
