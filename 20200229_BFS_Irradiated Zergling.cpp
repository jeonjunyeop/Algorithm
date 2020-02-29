//  저글링 방사능 오염 정올 1078
//  20200229_BFS_Irradiated Zergling.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 2/29/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;
int table[100][100];
bool visited[100][100];
int value[100][100];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int maximumValue,remainEntity;
void bfs(int y, int x){
    queue<pair<int, int>>q;
    q.push(make_pair(y, x));
    visited[y][x]=1;
    
    while(!q.empty()){
        pair<int, int> current = q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            int nextY = current.first+dir[i][0];
            int nextX = current.second+dir[i][1];
            if(0<=nextY&&nextY<n && 0<=nextX&&nextX<m && visited[nextY][nextX]==0&&table[nextY][nextX]==1){
                visited[nextY][nextX] = 1;
                value[nextY][nextX]= value[current.first][current.second]+1;
                q.push(make_pair(nextY, nextX));
            }
        }
    }
}

int main(){
    int y,x;
    cin >> m>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d",&table[i][j]);
        }
    }
    cin >>x>>y;
    bfs(y-1,x-1);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(table[i][j]==1 && visited[i][j]==0)
                remainEntity++;
            maximumValue = max(maximumValue, value[i][j]);
            //cout << value[i][j] << " ";
        }//cout<<"\n";
    }
    cout << maximumValue+3<<"\n";
    cout << remainEntity;
    //cout <<"end";
    return 0;
}
