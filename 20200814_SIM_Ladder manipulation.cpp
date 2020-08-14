// 백준 15684 사다리 조작
//  20200814_SIM_Ladder manipulation.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 8/14/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n,m,h,answer=987654321;
int table[32][12];

bool check(){
    for(int i=1; i<=n; i++){
        int x = i;
        for(int j = 1; j<=h; j++){
            if(table[j][x]==1){ // Right side
                x++;
            }else if(table[j][x-1] == 1){ // Left side
                x--;
            }
        }
        if(i!=x)
            return false;
    }
    return true;
}

void dfs(int row, int col, int cnt){
    if(cnt > 3){
        return;
    }
    if(check()==true){
//        cout<<"true"<<"\n";
        answer = min(answer, cnt);
        return;
    }
    for(int i=row; i<=h; i++){
        for(int j=1; j<n ;j++){
            if(table[i][j-1]==1 || table[i][j]==1 || table[i][j+1] ==1){
                continue;
            }else{
                table[i][j] = 1;
                dfs(i,j,cnt+1);
                table[i][j] = 0;
            }
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> h;
    int a,b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        table[a][b]=1;
    }
    
    dfs(1,1,0);
    if(answer==987654321){
        cout << -1 <<"\n";
        return 0;
    }
    cout << answer<<"\n";
    return 0;
}
