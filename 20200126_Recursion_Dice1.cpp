// 주사위 던지기1 _ 정올1169
//  20200126_Recursion_Dice1.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 1/26/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int N,M;
bool cache[7]={0,};
string dice[7] = {"0","1","2","3","4","5","6"};

void case1(string answer, int count){ // all the cases
    if(count==N){
        for(auto&x : answer)
            cout<<x;
        cout <<endl;
        return;
    }
    for(int i=1; i<7; i++)
        case1(answer + dice[i]+' ', count+1 );

}

void case2(int num, string answer, int count){ // except duplication [ ex)(1,2,1) and (2,1,1)]
    if(count==N){
        for(auto&x : answer)
            cout<<x;
        cout <<endl;
        return;
    }
    for(int i=num; i<7; i++)
        case2(i, answer + dice[i]+' ', count+1);

}

void case3(int num, string answer, int count){ // different numbers
    if(count==N){
        for(auto&x : answer)
            cout<<x;
        cout<<endl;
        return;
    }
    for(int i=1; i<7; i++){
        if(cache[i]==0){
            cache[i]=1;
            case3(i,answer+dice[i]+' ',count+1);
            cache[i]=0;
        }
    }
    return;
}

int main (){
    cin >>N>>M;
    if(M==1)
        case1("",0);
    else if(M==2)
        case2(1,"",0);
    else if(M==3)
        case3(1,"",0);
    return 0;
}
//2,088KB, 21ms
