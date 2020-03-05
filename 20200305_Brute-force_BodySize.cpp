// 덩치 _ 백준7568
//  20200305_Brute-force_BodySize.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 3/5/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int table[50][3];

void body_size(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i==j)
                continue;
            if(table[i][0]<table[j][0] && table[i][1]<table[j][1])
                table[i][2]++;
        }
    }
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> table[i][0] >> table[i][1];
        table[i][2]=1;
    }
    
    body_size();
    
    for(int i=0; i<N; i++)
        cout << table[i][2]<<" ";
    
    return 0;
}
