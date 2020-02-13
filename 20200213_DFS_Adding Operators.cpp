// 연산자 끼워넣기 백준14888
//  20200213_DFS_Adding Operators.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 2/13/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int pl,mi,mu,di;
int maxValue=-1147483646;
int minValue=1147483646;
int N, arr[12];
int temp;
void op(int sum, int count, int pl, int mi, int mu, int di){
    
    if(count==N){
        maxValue=max(maxValue,sum);
        minValue=min(minValue,sum);
        return;
    }
    if(pl>0)
        op(sum+arr[count], count+1, pl-1, mi, mu, di);
    if(mi>0)
        op(sum-arr[count], count+1, pl, mi-1, mu, di);
    if(mu>0)
        op(sum*arr[count], count+1, pl, mi, mu-1, di);
    if(di>0)
        op(sum/arr[count], count+1, pl, mi, mu, di-1);
}

int main(){
    cin >>N;
    for(int i=0; i<N; i++)
        cin>>arr[i];
    cin>>pl>>mi>>mu>>di;
    
    op(arr[0],1,pl,mi,mu,di);
    cout<<maxValue<<"\n";
    cout<<minValue<<"\n";
    
    return 0;
}
