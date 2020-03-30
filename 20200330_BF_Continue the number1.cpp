//
//  20200330_BF_Continue the number1.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 3/30/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
using namespace std;
int N,cnt;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    int number=1;
    int copy;
    int sum=0;
    
    while(number!=N+1){
        cnt=1;
        copy = number;
        while(copy){
            if(copy/10 >= 1)
                cnt++;
            copy/=10;
        }
        sum += cnt;
        number++;
    }
    
    cout << sum;

    return 0;
}

