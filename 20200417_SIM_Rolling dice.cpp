// 백준14499 주사위 굴리기
//  20200417_SIM_Rolling dice.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 4/17/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <queue>
using namespace std;
int table[20][20];
int dice[6];
int N,M,y,x,K;
queue<int> order;

void rotation(int dir, int arr[6]){
    //cout <<"dir:"<<dir<<"\n";
    int one = arr[0];
    int two = arr[1];
    int three = arr[2];
    int four = arr[3];
    int five = arr[4];
    int six = arr[5];
    if(dir==1){ //East
        arr[0] = four;
        arr[2] = one;
        arr[3] = six;
        arr[5] = three;
    }else if(dir==2){ // West
        arr[0] = three;
        arr[2] = six;
        arr[3] = one;
        arr[5] = four;
    }else if(dir==3){ //North
        arr[0] = five;
        arr[1] = one;
        arr[4] = six;
        arr[5] = two;
    }else if(dir==4){ //South
        arr[0] = two;
        arr[1] = six;
        arr[4] = one;
        arr[5] = five;
    }
}

void bfs(){
    while (!order.empty()) {
        int direction = order.front();
        order.pop();
        int ax = x;
        int ay = y;
        if(direction==1){
            x++;
        }else if(direction==2){
            x--;
        }else if(direction==3){
            y--;
        }else if(direction==4){
            y++;
        }
        
        if(0<=y&&y<N && 0<=x&&x<M ){
            //cout << "direction:"<<direction<<"\n";
            rotation(direction, dice);
            
            if(table[y][x]==0){
                table[y][x] = dice[5];
            }else if(table[y][x]!=0){
                dice[5] = table[y][x];
                table[y][x] = 0;
            }
                cout << dice[0]<<"\n"; // Print the top of the dice.
        }else{ // If the next position is out of range, ignore it.
            x = ax;
            y = ay;
        }
    }
}

int main(){
    cin >> N >> M >> y >> x >> K;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> table[i][j];
        }
    }
    int temp;
    for(int i=0; i<K; i++){
        cin >> temp;
        order.push(temp);
    }
    bfs();
    return 0;
}
