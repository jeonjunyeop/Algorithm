// 상범빌딩 백준6593
//  20200415_BFS_Dungeon Master(Sangbeom Bldg).cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 4/15/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
/*You are trapped in a 3D dungeon and need to find the quickest way out! The dungeon is composed of unit cubes which may or may not be filled with rock. It takes one minute to move one unit north, south, east, west, up or down. You cannot move diagonally and the maze is surrounded by solid rock on all sides.

Is an escape possible? If yes, how long will it take?

INPUT
The input file consists of a number of dungeons. Each dungeon description starts with a line containing three integers L, R and C (all limited to 30 in size).
L is the number of levels making up the dungeon.

R and C are the number of rows and columns making up the plan of each level.

Then there will follow L blocks of R lines each containing C characters. Each character describes one cell of the dungeon. A cell full of rock is indicated by a '#' and empty cells are represented by a '.'. Your starting position is indicated by 'S' and the exit by the letter 'E'. There's a single blank line after each level. Input is terminated by three zeroes for L, R and C.

OUTPUT
Each maze generates one line of output. If it is possible to reach the exit, print a line of the form
Escaped in x minute(s).
where x is replaced by the shortest time it takes to escape.
If it is not possible to escape, print the line
Trapped!*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
char table[30][30][30];
int value[30][30][30];
int L,R,C;
int dir[6][3] = {{0,0,-1},{0,0,1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};
pair<int, pair<int, int>> starting_point, end_point;
//void bfs(){    *********** WRONG FUNCTION****************
//   queue<pair<int, pair<int, int>>>q;
//    q.push(starting_point);
//    while (!q.empty()) {
//
//        int alayer = q.front().first;
//        int ay = q.front().second.first;
//        int ax = q.front().second.second;
//        q.pop();
//        //cout << "layer:"<<alayer<<" y:"<<ay<<" x:"<<ax<<"\n";
//        for(int i=0; i<6; i++){
//            int layer = alayer + dir[i][0];
//            int y = ay + dir[i][1];
//            int x = ax + dir[i][2];
//
//            if(0<=layer&&layer<L && 0<=y&&y<R && 0<=x&&x<C && value[layer][y][x]==0 ){
//                if(table[layer][y][x]=='.'){
//
//                    value[layer][y][x] = value[alayer][ay][ax]+1;
//                    q.push(make_pair(layer, make_pair(y, x)));
//                }
//                else if(table[layer][y][x]=='E'){
//                    value[layer][y][x] = value[alayer][ay][ax]+1;
//                    break;
//                }
//            }
//        }
//
//    }
//}     *********** WRONG FUNCTION****************
void bfs(){
   queue<pair<int, pair<int, int>>>q;
    q.push(starting_point);
    while (!q.empty()) {
        int alayer = q.front().first;
        int ay = q.front().second.first;
        int ax = q.front().second.second;
        q.pop();
        
        if(alayer==end_point.first && ay==end_point.second.first && ax==end_point.second.second){
            cout << "Escaped in " << value[alayer][ay][ax]<<" minute(s).\n";
            return;
        }
        //cout << "layer:"<<alayer<<" y:"<<ay<<" x:"<<ax<<"\n";// Trace the queue
        for(int i=0; i<6; i++){
            int layer = alayer + dir[i][0];
            int y = ay + dir[i][1];
            int x = ax + dir[i][2];
            
            if(0<=layer&&layer<L && 0<=y&&y<R && 0<=x&&x<C && value[layer][y][x]==0 ){
                if(table[layer][y][x]=='.' || table[layer][y][x]=='E'){
                    value[layer][y][x] = value[alayer][ay][ax]+1;
                    q.push(make_pair(layer, make_pair(y, x)));
                }
            }
        }
    }
    cout<<"Trapped!\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (1) {
        cin >> L >> R >> C;
        if(L==0&&R==0&&C==0)
            break;
        memset(value, 0, sizeof(value));

        for(int i=0 ;i<L; i++){
            for(int j=0; j<R; j++){
                for(int k=0; k<C; k++){
                    cin >> table[i][j][k];
                    if(table[i][j][k]=='S'){
                        starting_point.first = i;
                        starting_point.second.first=j;
                        starting_point.second.second=k;
                    }else if(table[i][j][k]=='E'){
                        end_point.first=i;
                        end_point.second.first=j;
                        end_point.second.second=k;
                    }
                }
            }
        }
        bfs();
//        for(int i=0 ;i<L; i++){ // Display the value table to see if it works correctly.
//            for(int j=0; j<R; j++){
//                for(int k=0; k<C; k++){
//                    cout << value[i][j][k];
//                }cout<<"\n";
//            }cout <<"\n";
//        }
    }
   
    return 0;
}
