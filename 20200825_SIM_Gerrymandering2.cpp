//
//  20200825_SIM_Gerrymandering2.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 8/25/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
// 백준17779 게리맨더링 2
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int N,gap=987654321;
int table[100][100];
//int line[100][100];
//void print_table(){
//    for(int i=0; i<10; i++){
//        for(int j=0; j<10; j++){
//            cout << line[i][j] <<" ";
//        }cout <<"\n";
//    }memset(line, 0, sizeof(line));
//    cout <<"\n";
//}

vector<int> zone_calculator(int y, int x, int d1, int d2){
    vector<int> v = {0,0,0,0,0};
    for(int i=0; i<N; i++){
        for(int j=0; j<N ;j++){
            if(j<=x && i<y+d1 && i+j<y+x){ // 1st area
                v[0]+=table[i][j];
//                line[i][j] = 1;
            }else if(j>x && i<=y+d2 && j-i>x-y){ // 2nd area
                v[1]+=table[i][j];
//                line[i][j] = 2;
            }else if(i>=y+d1 && j<x-d1+d2 && i-j>y+d1-(x-d1)){ // 3rd area
                v[2]+=table[i][j];
//                line[i][j] = 3;
            }else if(j>=x-d1+d2 && i>y+d2 && i+j>x+d2+y+d2){ // 4th area
                v[3]+=table[i][j];
//                line[i][j] = 4;
            }else{
                v[4]+=table[i][j];
//                line[i][j] = 5;
            }
        }
    }
    return v;
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> table[i][j];
        }
    }
    
    for(int y=0; y<N-2; y++){
        for(int x=1; x<N-1; x++){
            
            for(int d1=1; d1<N-1; d1++){
                for(int d2=1; d2<N-1; d2++){
                    
                    if(y+d1+d2<N && x-d1>=0 && x+d2<N){ // Possible case
                        vector<int> v = zone_calculator(y, x, d1, d2);
//                        cout << y<<","<<x<<"\n";
//                        for(auto & x : v){
//                            cout << x <<" ";
//                        }cout <<"\n";
                        sort(v.begin(), v.end());
                        gap = min(gap, v[4]-v[0]);
//                        print_table();
                    }
                    
                }
            }
            
        }
    }cout << gap<<"\n";
    return 0;
}
