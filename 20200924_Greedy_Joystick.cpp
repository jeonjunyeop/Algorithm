// 프로그래머스 _ 탐욕법 (Greedy) _ 조이스틱
//  20200924_Greedy_Joystick.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 9/24/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solution(string name) {
    int answer = 0;
    int len = name.size();
    
    for(int i=0; i<len; i++){
        if(name[i]!='A'){
            if(name[i]<=78)
                answer += name[i]-65;
            else
                answer += 91-name[i];
        }
    }
    
    int vertical = answer;
    
    int ftob = 0;
    int btof = 0;
    for(int i=1; i<len; i++)
        if(name[i]!='A')
            ftob=i;
    
    for(int i=1; i<len; i++)
        if(name[len-i]!='A')
            btof=i;
    
    if(ftob<=btof){
        answer += ftob;
    }else if(ftob>btof){
        answer += btof;
    }
    
    //--------------------
    // In case of (Right and left) or (Left and right)
    
    int first_point=0;
    for(int i=1; i<len; i++){
        if(name[i]!='A'){
            first_point = i;
            break;
        }
    }
    vector<pair<int, pair<int, int>>>v;
    int front_point = first_point;
    int back_point = 0;
    int middle = 0;
    if(first_point!=0){
        for(int i=first_point+1; i<len; i++){
            if(name[i]!='A'){
                if(middle>0){
                    v.push_back({middle,{front_point,i}});
                    middle=0;
                }
                front_point = i;
                
            }else{ // In case of 'A'
                //if(front)
                middle++;
            }
        }
    }
    int gobackway=987654321;
    if(v.size()){
        sort(v.begin(), v.end(), less<pair<int, pair<int, int>>>());
        int longgest = v[0].first;
        for(auto & x : v){
            int randl = 0;
            int landr = 0;
            int alen = x.first;
            int a = x.second.first;
            int b = x.second.second;
             //cout <<a<<", "<<b<<": "<< alen <<"\n";
            if(alen==longgest){
                randl = (2*a) + len-b;
                landr = (2*(len-b)) + a;
                gobackway = min(min(randl, landr)+vertical,gobackway);
            }
        }
    }
    answer = min(answer,gobackway);
    return answer;
}

void assertions(string name , int result){
    int answer = solution(name);
    if(answer == result){
        cout << "Correct answer! \n";
    }else{
        cout << "Wrong answer \n";
    }
    cout <<"Your answer: "<< answer<<"\n";
    cout <<"Provied answer: " << result<<"\n\n";
}

int main(){
    assertions("JEROEN", 56);
    assertions("JAN", 23);
    assertions("AAAAABA", 3);
    assertions("AAABAAA", 4);
    assertions("AAABBAAAABBA", 13);
    assertions("ABBBBB", 10);
    assertions("AABAAAAAAABBB", 11);
    assertions("BBAABBB", 10);
    //cout << (int)'A'<<"\n";
    //ABCDEFGHIJKLM(N)OPQRSTUVWXYZ
    //cout << (int)'N'<<"\n";
    //cout << (int)'Z'<<"\n";
    return 0;
}
