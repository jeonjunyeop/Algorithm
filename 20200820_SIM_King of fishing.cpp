//
//  20200820_SIM_King of fishing.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 8/20/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int R,C,M,sum;
int shrk[10001][5];
int table[101][101];
int dir[5][2] = {{0,0},{-1,0},{1,0},{0,1},{0,-1}};

//void print_table(){
//    for(int i=1; i<=R; i++){
//        for(int j=1; j<=C; j++){
//            cout << table[i][j] <<" ";
//        }cout <<"\n";
//    }cout <<"\n";
//}

void removing(int idx){
// Remove the shark's information.
        shrk[idx][4] = 0;
}

void moving(){
//    int temp[101][101];
//    for(int i=1; i<=R; i++){
//        for(int j=1; j<=C; j++){
//            temp[i][j] = table[i][j];
//        }
//    }
    for(int i=1; i<=M; i++){
        int r = shrk[i][0];
        int c = shrk[i][1];
        table[r][c] = 0;
    }

    for(int i=1; i<=M; i++){
        if(shrk[i][4] == 0) // Removed shark
            continue;
        
        int r = shrk[i][0];
        int c = shrk[i][1];
        int speed = shrk[i][2];
        int direction = shrk[i][3];
        int size = shrk[i][4];

        

       // table[r][c] = 0;

            for(int j=0; j<speed; j++){
                if(direction==1 || direction == 2){
                    int next = r + dir[direction][0];
                    if(next<1 || next > R)
                        direction = 3 - direction;
                    r += dir[direction][0];
                }else{
                    int next = c + dir[direction][1];
                    if(next<1 || next >C)
                        direction = 7-direction;
                    c += dir[direction][1];
                }
//                if(direction==1 && r==1){
//                    direction=2;
//                }else if(direction==2 && r==R){
//                    direction=1;
//                }else if(direction==3 && c==C){
//                    direction=4;
//                }else if(direction==4 && c==1){
//                    direction=3;
//                }
//                r += dir[direction][0];
//                c += dir[direction][1];

            }
//        cout <<"("<< r<<","<<c<<") "<<i<<" d:"<<direction<<"\n";

        if(table[r][c]!=0){
            if(shrk[table[r][c]][4]<size){ // edible
                shrk[table[r][c]][4] = 0;
                table[r][c] = i;
                shrk[i][0] = r;
                shrk[i][1] = c;
                shrk[i][3] = direction;
            }else{
                shrk[i][4] = 0;
            }
        }else{
            table[r][c] = i;
            shrk[i][0] = r;
            shrk[i][1] = c;
            shrk[i][3] = direction;
        }


    }
}

int main(){
    
    cin >> R >> C >> M;

    for(int i=1; i<=M; i++)
        for(int j=0; j<5; j++) // r, c, s, d, z
            cin >> shrk[i][j];

    for(int i=1; i<=M; i++){
        int y = shrk[i][0];
        int x = shrk[i][1];
        table[y][x]=i;
    }

    for(int i=1; i<=C; i++){
//        cout <<"Stage "<< i <<"\n";
//        cout << "start\n";
//        print_table();

        for(int j=1; j<=R; j++){
            if(table[j][i]!=0){ // Catch
//                cout <<"Catch\n";
                int idx = table[j][i];
                sum += shrk[idx][4];
                table[j][i]=0;
                shrk[idx][4] = 0;
                break;
            }
        }

//        cout <<"Fishing\n";
//        print_table();

        moving();
//        cout << "Moving\n";
//        print_table();

    }
    cout << sum <<"\n";
    return 0;
}
