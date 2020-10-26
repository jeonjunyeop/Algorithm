//
//  20201026_SIM_Magician&Tornado.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 10/26/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.

// 백준20057 마법사 상어와 토네이도
#include <iostream>
#include <sstream>
using namespace std;

int table[500][500];
// 0,1,2,3 : W,S,E,N
int dir[4][2] = {{0,-1},{1,0},{0,1},{-1,0}};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> table[i][j];

    int y = n/2; // initial y
    int x = n/2; // initial x
    int d = 0; // direction
    int answer = 0; // total value
    int turn = 0; // loop count
    int gap = 1;
    int prev = 0; // previous rotation point
    int cnt = 0;
    bool rotation = false;
    while (1) {
        turn++;

        if(cnt>1 &&cnt%2==0 && rotation==false){
            gap++;
            rotation = true;
        }
        y += dir[d][0];
        x += dir[d][1];
        
        int top_y = y+(dir[d][0]*2);
        int top_x = x+(dir[d][1]*2);
        int lt_y = y+dir[d][0] + dir[(d+1)%4][0];
        int lt_x = x+dir[d][1] + dir[(d+1)%4][1];
        int rt_y = y+dir[d][0] + dir[(d+3)%4][0];
        int rt_x = x+dir[d][1] + dir[(d+3)%4][1];
        int fl_y = y+(dir[(d+1)%4][0]*2);
        int fl_x = x+(dir[(d+1)%4][1]*2);
        int ml_y = y+dir[(d+1)%4][0];
        int ml_x = x+dir[(d+1)%4][1];
        int mr_y = y+dir[(d+3)%4][0];
        int mr_x = x+dir[(d+3)%4][1];
        int fr_y = y+(dir[(d+3)%4][0]*2);
        int fr_x = x+(dir[(d+3)%4][1]*2);
        int bl_y = y+dir[(d+1)%4][0]+dir[(d+2)%4][0];
        int bl_x = x+dir[(d+1)%4][1]+dir[(d+2)%4][1];
        int br_y = y+dir[(d+2)%4][0]+dir[(d+3)%4][0];
        int br_x = x+dir[(d+2)%4][1]+dir[(d+3)%4][1];
        
        int info[9][2] = {{top_y,top_x},{lt_y,lt_x},{rt_y,rt_x},{fl_y,fl_x},{ml_y,ml_x},{mr_y,mr_x},{fr_y,fr_x},{bl_y,bl_x},{br_y,br_x}};
        
        int sum = 0;
        int original = table[y][x];
        
        for(int i=0; i<9; i++){
            
            int sand=original;
            
            if(i==0){
                sand = original*5/100;
            }else if(i==1 || i==2){
                sand = original*10/100;
            }else if(i==3 || i ==6){
                sand = original*2/100;
            }else if(i==4 || i==5){
                sand = original*7/100;
            }else if(i==7 || i==8){
                sand = original/100;
            }
            
            if(info[i][0]<0 || info[i][0]>=n || info[i][1]<0 || info[i][1]>=n){
                answer += sand;
            }else{
                table[info[i][0]][info[i][1]] += sand;
            }
            sum+=sand;
        }
        
        if(y+dir[d][0]<0 || y+dir[d][0]>=n || x+dir[d][1]<0 || x+dir[d][1]>=n){
            answer += original-sum; // a
        }else{
            table[y+dir[d][0]][x+dir[d][1]] += original-sum; // a
        }
        table[y][x] = 0; // clear
        
        if(y==0 && x==0){
            break;
        }
        
        // PRINT TO SEE IF OK
//        cout << " *** Stage" << turn<<"\n";
//        cout << "sum: "<< sum<<"\n";
//        cout <<"(y,x): ("<<y<<","<<x<<")\n";
//        for(int i=0; i<n; i++){
//            for(int j=0; j<n; j++){
//                cout << table[i][j]<<"|";
//            }cout <<"\n";
//        }cout <<"\n";
        
        
        if(turn-prev == gap){ // Rotation
            d = (d+1)%4;
            cnt++;
            rotation = false;
            prev = turn;
        }

        if(y==0 && x==0)
            break;
    }
    cout << answer <<"\n";
    return 0;
}
