// 프로그래머스 _ 2019 KAKAO BLIND RECRUITMENT _ 오픈채팅방
//  20200903_Kakao_Open chatroom.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 9/3/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> m;
    
    // Update the nickname
    for(int i=0; i<record.size(); i++){
        string uid = "";
        string nickname="";
        
        if(record[i][0] == 'E'){
            int idx = 6;
            while (record[i][idx]!=' ') {
                uid.push_back(record[i][idx]);
                idx++;
            }
            nickname = record[i].substr(idx+1);
            m[uid] = nickname;
        
        }else if(record[i][0] =='C'){
            int idx = 7;
            while (record[i][idx]!=' ') {
                uid.push_back(record[i][idx]);
                idx++;
            }
            nickname = record[i].substr(idx+1);
            m[uid] = nickname;
        }
    }
    
    //Insert the each result
    for(int i=0; i<record.size(); i++){
        string uid = "";
        int idx = 6;
        while (record[i][idx]!=' ') {
            uid.push_back(record[i][idx]);
            idx++;
            if(idx==record[i].size())
                break;
        }
        if(record[i][0] == 'E')
            answer.push_back(m[uid]+"님이 들어왔습니다.");
        else if(record[i][0] =='L')
            answer.push_back(m[uid]+"님이 나갔습니다.");
        
    }

    return answer;
}
void assertions(vector<string> r,  vector<string> result){
    vector<string> answer = solution(r);
    if(answer == result){
        cout << "Correct answer \n";
    }else{
        cout << "Wrong answer \n";
    }
    for(auto & x : answer)
        cout << x<<"\n";
    cout <<"\n";
   
}

int main(){
    assertions({"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"}, {"Prodo님이 들어왔습니다.", "Ryan님이 들어왔습니다.", "Prodo님이 나갔습니다.", "Prodo님이 들어왔습니다."});

    return 0;
}
