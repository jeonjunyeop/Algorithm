// 체스판 다시 칠하기 백준 1018
//  20200304_BruteForce_RepaintingChessboard.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 3/4/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
char chess1[8][8];
char chess2[8][8];
char table[50][50];
int N,M,answer=64;
int pAnswer1, pAnswer2;

void initialization(){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if((i+j)%2==0){
                chess1[i][j]='B';
                chess2[i][j]='W';
            }else{
                chess1[i][j]='W';
                chess2[i][j]='B';
            }
        }
    }
}

void comparing(int y, int x){
    //cout << "y= "<<y<<" ,x= "<<x<<"\n";
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(chess1[i][j] != table[y+i][x+j]){
                pAnswer1++;
            }
            if(chess2[i][j] != table[y+i][x+j]){
                pAnswer2++;
            }
        }
    }
    answer=min(answer, min(pAnswer1, pAnswer2));
    //cout << answer<<"\n";
    pAnswer2=0;
    pAnswer1=0;
}

void overlapping(){
    for(int i=0; i<=N-8; i++)
        for(int j=0; j<=M-8; j++)
            comparing(i, j);
}

int main(){
    initialization();
    cin>> N >>M;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> table[i][j];
    
    overlapping();
    cout << answer<<"\n";
    return 0;
}
