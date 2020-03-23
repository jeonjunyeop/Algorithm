//  별찍기 백준2447
//  20200323_Recursion_Drawing stars.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 3/23/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
using namespace std;
int N;
int table[2187][2187];

void drawing(int y, int x, int size){
    if(size==1){
        table[y][x]=1;
        return;
    }else{
        int athird = size/3;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(i==1 && j==1)
                    continue;
                drawing(y+(i*athird), x+(j*athird), athird);
            }
        }
    }
}

int main(){
    cin >> N;
    drawing(0, 0, N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(table[i][j]==1)
                cout << "*";
            else
                cout <<" ";
        }cout <<"\n";
    }
    return 0;
}


