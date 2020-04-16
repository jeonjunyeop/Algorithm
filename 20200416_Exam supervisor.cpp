// 백준13458시험감독
//  20200416_Exam supervisor.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 4/16/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, B, C,maxValue;
long long total;
int arr[1000001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >>N;
    for(int i=0; i<N; i++)
        cin>>arr[i];
    cin>>B>>C;
    
    total = N;
    for(int i=0; i<N; i++){
        arr[i] -= B;
        if(arr[i]>0){ // ****important condition****
            int result = arr[i]/C;
            if(arr[i]%C>0)
                total++;
            total+=result;
        }
    }
    cout << total;
    return 0;
}

