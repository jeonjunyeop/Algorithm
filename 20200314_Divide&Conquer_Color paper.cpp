// 색종이 만들기 _ 백준2630
//  20200314_Divide&Conquer_Color paper.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 3/14/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <algorithm>

using namespace std;
int table[128][128];
int papers[2];

bool check(int y, int x, int size){
    for(int i=y; i<y+size; i++){
        for(int j=x; j<x+size; j++){
            if(table[i][j]!=table[y][x])
                return false;
        }
    }
   
    return true;
}

void dividing(int y, int x, int size){
    if(size==1 || check(y, x, size)){
        papers[table[y][x]]++;
    }else{
        dividing(y, x, size/2);
        dividing(y+size/2, x, size/2);
        dividing(y, x+size/2, size/2);
        dividing(y+size/2, x+size/2, size/2);
        
    }
            
}

int main(){
    int N=0;
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>> table[i][j];
        }
    }
    dividing(0, 0, N);
    cout << papers[0]<<"\n"<<papers[1];
    return 0;
}


