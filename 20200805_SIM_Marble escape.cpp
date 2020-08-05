// 백준13460 구슬 탈출 2
//  20200805_SIM_Marble escape.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 8/5/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int n,m,ry,rx,by,bx;
char table[10][10];
int dir[4][2] = {{0,-1},{-1,0},{0,1},{1,0}}; // 0:W, 1:N, 2:E, 3:S

void bfs(){
    queue<vector<int>>q;
    q.push({ry,rx,by,bx,-1,0});
    while (!q.empty()) {
        int rry = q.front()[0];
        int rrx = q.front()[1];
        int bby = q.front()[2];
        int bbx = q.front()[3];
        int direction = q.front()[4];
        int distance = q.front()[5]+1;
        q.pop();
        if(distance>10){
           
            cout<<"-1"<<"\n";
            return;
        }
        
        for(int i=0; i<4; i++){
            
            if(direction!=-1 && (direction==i || (direction+i)%2==0)){
                continue;
            }
            
            char temp[10][10];
            for(int q=0; q<n; q++){
                for(int w=0; w<m; w++){
                    temp[q][w] = table[q][w];
                }
            }
            
           // cout <<direction <<", "<< i <<"\n";
            int n_ry = rry;
            int n_rx = rrx;
            int n_by = bby;
            int n_bx = bbx;
            
            temp[ry][rx] = '.';
            temp[by][bx] = '.';
            temp[n_ry][n_rx] = 'R';
            temp[n_by][n_bx] = 'B';
            
            bool order = true;
            bool enter = false;
            bool r_move = true;
            bool b_move = true;
            
            if(i==0){
                if(n_rx<n_bx)
                    order=true;
                else
                    order=false;
            }else if(i==1){
                if(n_ry<n_by)
                    order=true;
                else
                    order=false;
            }else if(i==2){
                if(n_rx>n_bx)
                    order=true;
                else
                    order=false;
            }else if(i==3){
                if(n_ry>n_by)
                    order=true;
                else
                    order=false;
            }
            
            if(order==true){ // Red first
                int cnt=0;
                while (1) { //Red
                    if(temp[n_ry+dir[i][0]][n_rx+dir[i][1]]=='O'){
                        temp[n_ry][n_rx] = '.';
                        n_ry += dir[i][0];
                        n_rx += dir[i][1];
                        enter=true;
                        break;
                    }else{
                        if(temp[n_ry+dir[i][0]][n_rx+dir[i][1]]=='.'){
                            temp[n_ry][n_rx] = '.';
                            n_ry += dir[i][0];
                            n_rx += dir[i][1];
                            temp[n_ry][n_rx] = 'R';
                        }else{
                            if(cnt==0)
                                r_move=false;
                            break;
                        }
                    }
                    cnt++;
                }
                cnt=0;
                while (1) { // Blue
                    if(temp[n_by+dir[i][0]][n_bx+dir[i][1]]=='R'){
                        break;
                    }else if(temp[n_by+dir[i][0]][n_bx+dir[i][1]]=='O'){
                        temp[n_by][n_bx] = '.';
                        n_by += dir[i][0];
                        n_bx += dir[i][1];
                        enter=false;
                        break;
                    }else{
                        if(temp[n_by+dir[i][0]][n_bx+dir[i][1]]=='.'){
                            temp[n_by][n_bx] = '.';
                            n_by += dir[i][0];
                            n_bx += dir[i][1];
                            temp[n_by][n_bx] = 'B';
                        }else{
                            if(cnt==0)
                                b_move=false;
                            break;
                        }
                    }
                    cnt++;
                }
                
            }else{ // Blue first
                int cnt=0;
                while (1) { // Blue
                    if(temp[n_by+dir[i][0]][n_bx+dir[i][1]]=='O'){
                        temp[n_by][n_bx] = '.';
                        n_by += dir[i][0];
                        n_bx += dir[i][1];
                        break;
                    }else{
                        if(temp[n_by+dir[i][0]][n_bx+dir[i][1]]=='.'){
                            temp[n_by][n_bx] = '.';
                            n_by += dir[i][0];
                            n_bx += dir[i][1];
                            temp[n_by][n_bx] = 'B';
                        }else{
                            if(cnt==0)
                                b_move=false;
                            break;
                        }
                    }
                    cnt++;
                }
                cnt=0;
                while (1) { //Red
                    if(temp[n_ry+dir[i][0]][n_rx+dir[i][1]]=='B'){
                        break;
                    }else if(temp[n_ry+dir[i][0]][n_rx+dir[i][1]]=='O'){
                        temp[n_ry][n_rx] = '.';
                        n_ry += dir[i][0];
                        n_rx += dir[i][1];
                        enter=true;
                        break;
                    }else{
                        if(temp[n_ry+dir[i][0]][n_rx+dir[i][1]]=='.'){
                            temp[n_ry][n_rx] = '.';
                            n_ry += dir[i][0];
                            n_rx += dir[i][1];
                            temp[n_ry][n_rx] = 'R';
                        }else{
                            if(cnt==0)
                                r_move=false;
                            break;
                        }
                    }
                    cnt++;
                }
            }
            if(temp[n_by][n_bx]=='O'){
                continue;
            }else if(enter==true){
                cout <<distance<<"\n";
                return;
            }
            
            if(r_move==false && b_move==false)
                continue;
            
            q.push({n_ry, n_rx, n_by, n_bx, i, distance});
//            cout << "red: ("<<n_ry<<","<<n_rx<<")\n";
//            cout << "blue: ("<<n_by<<","<<n_bx<<")\n";
//            cout << "direction: "<<i<<"\n";
//            cout << "total: "<<distance<<"\n";
//            cout <<"----------------\n";
        }
    }
   
    cout <<-1<<"\n";
    return;
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> table[i][j];
            if(table[i][j]=='B'){
                by = i;
                bx = j;
            }else if(table[i][j]=='R'){
                ry = i;
                rx = j;
            }
        }
    }
    bfs();
    return 0;
}
