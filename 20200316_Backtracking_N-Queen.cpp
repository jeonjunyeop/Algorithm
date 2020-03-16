// N-Queen
//  20200316_Backtracking_N-Queen.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 3/16/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
using namespace std;
int N,cnt;
int table[16];

// *********Time Limit Exceed**********
//bool check(int y, int x){
//    for(int i=1; i<=N ;i++)
//        for(int j=1; j<=N; j++)
//            if(table[i]==j)
//                if(i+j==y+x || i-j==y-x || x==j)
//                    return false;
//    return true;
//} *********Time Limit Exceed**********

bool check(int y, int x){
    for(int i=1; i<=N ;i++){
        if(table[i]!=0){
            if(i+table[i]==y+x || i-table[i]==y-x || x==table[i]){
                return false;
            }
        }
    }
    return true;
}

void nqueen(int y, int x){
    if(y==N+1){
        cnt++;
        return;
    }
    for(int i=1; i<=N; i++){
        if(check(y, i)){
            table[y]=i;
            nqueen(y+1, i);
            table[y]=0;
        }
    }
}

int main(){
    cin >> N;
    nqueen(1, 0);
    cout << cnt;
    return 0;
}


