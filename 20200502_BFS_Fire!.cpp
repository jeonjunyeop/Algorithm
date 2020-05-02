// 백준4179 불!
//  20200502_BFS_Fire!.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 5/2/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
/*Joe works in a maze. Unfortunately, portions of the maze have caught on fire, and the owner of the maze neglected to create a fire escape plan. Help Joe escape the maze.

Given Joe's location in the maze and which squares of the maze are on fire, you must determine whether Joe can exit the maze before the fire reaches him, and how fast he can do it.

Joe and the fire each move one square per minute, vertically or horizontally (not diagonally). The fire spreads all four directions from each square that is on fire. Joe may exit the maze from any square that borders the edge of the maze. Neither Joe nor the fire may enter a square that is occupied by a wall.

INPUT
The first line of input contains the two integers R and C, separated by spaces, with 1 <= R,C <= 1000. The following R lines of input each contain one row of the maze. Each of these lines contains exactly C characters, and each of these characters is one of:

#, a wall
., a passable square
J, Joe's initial position in the maze, which is a passable square
F, a square that is on fire
There will be exactly one J in the input.

OUTPUT
Output a single line containing IMPOSSIBLE if Joe cannot exit the maze before the fire reaches him, or an integer giving the earliest time Joe can safely exit the maze, in minutes.*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int m,n,value;
char table[1000][1000];
int fire_table[1000][1000];
int j_route[1000][1000];
queue<pair<int, int>> fq;
queue<pair<int, int>> jq;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
void bfs(){
    //Spread of the fire
    while (!fq.empty()) {
        int ay = fq.front().first;
        int ax = fq.front().second;
        fq.pop();
        for(int i=0; i<4; i++){
            int y = ay + dir[i][0];
            int x = ax + dir[i][1];
        
            if(0<=y&&y<n && 0<=x&&x<m && table[y][x]!='#' && fire_table[y][x]==0){
                fq.push({y,x});
                fire_table[y][x] = fire_table[ay][ax]+1;
            }
        }
    }
    //Jihoon's route
    while (!jq.empty()) {
               int ay = jq.front().first;
               int ax = jq.front().second;
               jq.pop();
            if(ay==0 || ay == n-1 || ax == 0 || ax == m-1){
                value = j_route[ay][ax];
                break;
            }
               for(int i=0; i<4; i++){
                   int y = ay + dir[i][0];
                   int x = ax + dir[i][1];
                   if(0<=y&&y<n && 0<=x&&x<m && table[y][x]=='.'&&j_route[y][x]==0){
                       if(j_route[ay][ax]+1 < fire_table[y][x] || fire_table[y][x]==0){
                           jq.push({y,x});
                           j_route[y][x] = j_route[ay][ax]+1;
                       }
                   }
               }
       }
}

int main(){

    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> table[i][j];
            if(table[i][j]=='F'){
                fq.push({i,j});
                fire_table[i][j]=1;
            }
            else if(table[i][j]=='J'){
                jq.push({i,j});
                j_route[i][j]=1;
            }
        }
    }
    bfs();

//    for(int i=0; i<n; i++){
//        for(int j=0; j<m; j++){
//            cout << fire_table[i][j] <<" ";
//        }cout <<"\n";
//    }cout <<"\n";
//    for(int i=0; i<n; i++){
//        for(int j=0; j<m; j++){
//            cout << j_route[i][j] <<" ";
//        }cout <<"\n";
//    }cout <<"\n";

    if(value==0)
        cout<< "IMPOSSIBLE";
    else
        cout <<value;

    return 0;
}
