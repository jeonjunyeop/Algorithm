// Lotto _ 백준6603 _ University of Ulm Local Contest 1996 F
//  20200401_Brute-force_Lotto.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 4/1/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int num[14];
int k;
vector<int> v;

void lotto(int idx){
    if(idx>k || v.size()>6)
        return;
    if(v.size() == 6){
        for(int i=0; i<6; i++)
            cout << v[i]<<" ";
        cout <<"\n";
    }
    for(int i=idx+1; i<=k; i++){
        v.push_back(num[i]);
        lotto(i);
        v.pop_back();
    }
}

int main(){
    while(1){
        cin >> k;
        if(k==0)
            break;
        for(int i=1; i<=k; i++){
            cin >>num[i];
        }
        lotto(0);
        cout <<"\n";
    }
    return 0;
}
