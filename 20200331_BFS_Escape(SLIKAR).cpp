// 탈출 백준3055
//  20200331_BFS_Escape(SLIKAR).cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 3/31/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
/*The evil emperor Cactus has in his possession the Magic Keg and has flooded the Enchanted Forest! The Painter and the three little hedgehogs now have to return to the Beaver's den where they will be safe from the water as quickly as possible!

The map of the Enchanted Forest consists of R rows and C columns. Empty fields are represented by '.' characters, flooded fields by '*' and rocks by 'X'. Additionally, the Beaver's den is represented by 'D' and the Painter and the three little hedgehogs are shown as 'S'.

Every minute the Painter and the three little hedgehogs can move to 4 neighbouring fields (up, down, left or right). Every minute the flood expands as well so that all empty fields that have at least one common side with a flooded field become flooded as well. Neither water nor the Painter and the three little hedgehogs can pass through rocks. Naturally, the Painter and the three little hedgehogs cannot pass through flooded fields, and water cannot flood the Beaver's den.

Write a program that will, given a map of the Enchanted Forest, output the shortest time needed for the Painter and the three little hedgehogs to safely reach the Beaver's den.

Note: The Painter and the three little hedgehogs cannot move into a field that is about to be flooded (in the same minute).

****INPUT****
The first line of input will contain two integers, R and C, smaller than or equal to 50.

The following R lines will each contain C characters ('.', '*', 'X', 'D' or 'S'). The map will contain exactly one 'D' character and exactly one 'S' character.

****OUTPUT****
Output the shortest possible time needed for the Painter and the three little hedgehogs to safely reach the Beaver's den. If this is impossible output the word “KAKTUS” on a line by itself.*/
#include <iostream>
#include <queue>
using namespace std;
int R,C;
char table[50][50];
int flood_table[50][50];
int route[50][50];
int dir[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};

queue<pair<int, int>> fq;
queue<pair<int, int>> sq;
void bfs(){
    
    while (!fq.empty()) { // FLOOD
        int ay = fq.front().first;
        int ax = fq.front().second;
        fq.pop();
        for(int i=0 ;i<4; i++){
            int y = ay+dir[i][0];
            int x = ax+dir[i][1];
            if(0<=x&&x<C && 0<=y&&y<R && flood_table[y][x]==0 && table[y][x]=='.'){
                flood_table[y][x] = flood_table[ay][ax]+1;
                fq.push(make_pair(y, x));
            }
        }
    }
    
    while(!sq.empty()){ // ROUTE OF THE CHARACTOR
        int ay = sq.front().first;
        int ax = sq.front().second;
        sq.pop();
        for(int i=0; i<4; i++){
            int y = ay + dir[i][0];
            int x = ax + dir[i][1];
            if(0<=x&&x<C && 0<=y&&y<R && route[y][x]==0 && (route[ay][ax]+1<flood_table[y][x] || flood_table[y][x]==0)){
                if(table[y][x]=='.' || table[y][x] == 'D'){
                    route[y][x] = route[ay][ax]+1;
                    sq.push(make_pair(y, x));
                }
            }
        }
    }
}

int main(){
    int a=0,b=0;
    cin >> R>>C;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> table[i][j];
            if(table[i][j]=='*')
                fq.push(make_pair(i, j));
            else if(table[i][j]=='S')
                sq.push(make_pair(i, j));
            else if(table[i][j]=='D'){
                a=i;
                b=j;
            }
        }
    }
    bfs(); // BFS
    
    if(route[a][b]==0){
        cout << "KAKTUS";
        return 0;
    }cout << route[a][b]<<"\n";
    
//    for(int i=0; i<R ;i++){
//        for(int j=0; j<C ; j++){
//            cout << flood_table[i][j]<<" ";
//        }cout << "\n";
//    }cout<<"\n";
//    for(int i=0; i<R ;i++){
//        for(int j=0; j<C ; j++){
//            cout << route[i][j]<<" ";
//        }cout << "\n";
//    }
    
    return 0;
}
