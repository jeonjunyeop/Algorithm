//Numerous local and international recreational runners were eager to take part in this year’s Zagreb Marathon! It is an already traditional race 42 125 meters long. A curious statistical info is that this year every single contestant managed to complete the race, except one.
//Since marathons are all about taking part, help the organizers figure out, based on the list of registered contestants and ranking list, the identity of the contestant that did not complete the race.
//------INPUT-------
//The first line of input contains the integer N (1 􏰀 N 􏰀 105), the number of contestants.
//Each of the following N lines contains the names of registered contestants.
//The additional N−1 lines contain the names of contestants in the order which they completed the race.
//The contestants’ names will consist of at least one and at most twenty lowercase letters of the English alphabet. The contestants’ names won’t necessarily be unique.
//-------OUTPUT-------
//The first and only line of output must contain the name of the contestant who didn’t finish the race.
//-------SCORING-------
//In test cases worth 50% of total points, it will hold 1 􏰀 N 􏰀 1 000.

//  20191202 Hash_Zagreb Marathon.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 12/2/19.
//  Copyright © 2019 Junyeop Jeon. All rights reserved.

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string,int> d;
    
    for (auto& i : participant)
        d[i]++;
    
    for (auto& i : completion)
        d[i]--;
    
    for(auto&i : d){
        if(i.second>0){
            answer = i.first;
            break;
        }
    }
    
    return answer;
}
