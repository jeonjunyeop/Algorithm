//Olympiad > Croatian Highschool Competitions in Informatics > 2005 > National Competition #1 - Juniors 2nd
// zmija _ 백준 3190 뱀

//  20200416_SIM_zmija (snake).cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 4/16/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
/*
One of the most popular DOS games is 'Dummy'. The snake is crawling through the board and eating apples that increase its length. The game ends when the snake bumps into itself or into the wall.

Game board consists of NxN squares arranged in N rows and N columns, and some squares contain apples. Around the board there is a wall. At the beginning of the game, the snake is located in the top-left corner, its length is equal to 1 and its head is directed towards right.

Snake is crawling by changing its position during each second according to the following rules:

first, snake extends its length by spreading to the next square in front of the head (i.e. in the direction of the head),
if there is an apple on that square, tail of the snake does not move (hence, its length is increased by 1 in this step),
if there is no apple, last square of the tail is erased (hence, its length stays unchanged)
Positions of the apples and movements of the snake are given. Write a program that will calculate the number of seconds until the game ends.

INPUT
First line of input contains an integer N, 2 ≤ N ≤ 100.

Following line contains an integer K, 0 ≤ K ≤ 100, the number of apples on the board.

Following K lines contain coordinates of apples on the board. First number denotes the row and second number denotes the column of the board where the apple is situated. There will be no apple at the top-left corner of the board.

Following line contains an integer number L, 1 ≤ L ≤ 100, the number of times the snake makes a turn.

Each of the following L lines contains the description of one turn. A single turn is described by a number X (positive integer less than or equal to 10,000) and a character C. This means that the snake rotates its head 90 degrees left (if C is 'L') or right (if C is 'D') at the end of the Xth second

OUTPUT
First and only line of output should contain number of seconds from the problem statement.*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
int N, K, L, cycle, direction;
unordered_map<int, char> rotation;
queue<pair<int, int>>q;
queue<pair<int, int>>snake;
int table[102][102];
bool apple[102][102];
void bfs(){
    q.push(make_pair(1, 1));
    snake.push(make_pair(1, 1));
    table[1][1]=1;
    while(!q.empty()){
        cycle++;
        int y = q.front().first;
        int x = q.front().second;
        int sy = snake.front().first;
        int sx = snake.front().second;
        q.pop();
        
//        cout <<"cycle:"<<cycle<<" dir:"<<direction<<" ("<< y<<","<<x<<")\n";
//        for(int i=0; i<=N; i++){
//            for(int j=0; j<=N; j++){
//                cout << table[i][j]<<" ";
//            }cout<<"\n";
//        }
         
        //define the next cell
        if(direction==0){
            x++;
        }else if(direction==3){
            y++;
        }else if(direction==2){
            x--;
        }else if(direction==1){
            y--;
        }

        //condition that can finish the game
        if(y<=0||y>N || x<=0||x>N || table[y][x]==1){
            //cout <<"y,x="<<y<<","<<x<<" return\n";
            return;
        }else{
            table[y][x]=1;
            q.push(make_pair(y, x));
            snake.push(make_pair(y, x));
            
            //Delete the tail
            if(apple[y][x]==0){
                table[sy][sx]=0;
                snake.pop();
            }else{ // *************once the apple is eaten, it should be removed*************.
                apple[y][x]=0;
            }
        }
        
        //redefine the next direction
        if(rotation[cycle]=='L'){
            direction = (direction+1)%4;
        }else if(rotation[cycle]=='D'){
            direction = ((direction+4)-1)%4;
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >>K;
    int a, b;
    for(int i=0; i<K ;i++){
        cin >> a >> b;
        apple[a][b]=1;
    }
    cin >> L;
    int ta;
    char tb;
    for(int i=0; i<L; i++){
        cin >> ta;
        cin >> tb;
        rotation[ta]=tb;
    }
    bfs();
    cout << cycle;
    return 0;
}

