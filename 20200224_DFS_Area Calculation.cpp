// 영역구하기 정올 1457
//  20200224_DFS_Area Calculation.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 2/24/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int N,M,K;
int table[100][100];
bool visited[100][100];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int arr[5000];
vector<int> v;

void dfs(int y, int x, int count){
    arr[count]++;
    for(int i=0; i<4; i++){
        int movY = y+dir[i][0];
        int movX = x+dir[i][1];
        if(0<=movX&&movX<N && 0<=movY&&movY<M && visited[movY][movX]==0 && table[movY][movX]==0){
                visited[movY][movX]=1;
                dfs(movY, movX, count);
        }
    }
}

int main(){
    cin >> M >> N >>K;
    int a,b,c,d,count=0;
    for(int t=0; t<K; t++){
        cin >> a>> b>> c>> d;
        for(int i=b; i<d; i++)
            for(int j=a; j<c; j++)
                table[i][j]=1;
    }

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(table[i][j]==0 && visited[i][j]==0){
                count++;
                visited[i][j]=1;
                dfs(i,j,count);
               // cout <<"dfs called"<<"\n";
            }
        }
    }
    cout << count<<"\n";
//    for(int i=0; i<M; i++){
//        for(int j=0; j<N; j++){
//            cout << table[i][j]<<" ";
//        }cout <<"\n";
//    }cout <<"\n";
//
//    for(int i=0; i<M; i++){
//        for(int j=0; j<N; j++){
//            cout << visited[i][j]<<" ";
//        }cout <<"\n";
//    }cout <<"\n";

    for(int i=1; i<count+1; i++)
        v.push_back(arr[i]);
    sort(v.begin(), v.end(), greater<int>());
    for(int i=0; i<count; i++){
        cout << v.back()<<" ";
        v.pop_back();
    }
    return 0;
}
