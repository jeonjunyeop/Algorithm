// 양팔저울 _ 정올1352
//  20200125_DP_Balances.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 1/25/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int marble[7];
int weight[30];
int cache[31][40001];
int marbleNum, weightNum;

void table(int count, int value){
    if(count>weightNum)
        return;
    if(cache[count][value]!=-1)
        return;
    cache[count][value]=1;
    
    table(count+1, value+weight[count]);
    table(count+1, value);
    table(count+1, abs(value-weight[count]));
}

int main(){
    memset(cache, -1, sizeof(cache));
    cin>> weightNum;
    for(int i=0 ;i<weightNum; i++)
        cin >>weight[i];
    cin >> marbleNum;
    for(int i=0 ;i<marbleNum; i++)
        cin>> marble[i];
    
    table(0,0);
    
    for(int i=0; i<marbleNum; i++){
        if(cache[weightNum][marble[i]]==1)
            cout <<"Y";
        else
            cout <<"N";
        cout<<" ";
    }
    
    return 0;
}
