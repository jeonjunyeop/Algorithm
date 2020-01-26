// 주사위 던지기 2 _ 정올1175
//  20200126_Recursion_Dice2.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 1/26/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
using namespace std;
int N,M;
string dice[7] = {"0","1","2","3","4","5","6"};

void operation(int sum, string answer, int count){
    if(count == N){
        if(sum==M){
            for(auto& x : answer)
                cout<< x;
            cout <<endl;
        }
        return;
    }
    
    for(int i=1; i<7; i++)
        operation(sum+i, answer+dice[i]+" ", count+1);
}

int main(){
    cin >> N>> M;
    operation(0,"",0);
    return 0;
}
