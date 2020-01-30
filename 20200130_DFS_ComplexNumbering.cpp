// 단지번호붙이기 _ 백준2667
//  20200130_DFS_ComplexNumbering.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 1/30/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
int table[26][26];
bool visited[26][26];
int rangeX[4]={0,0,-1,1};
int rangeY[4]={1,-1,0,0};
int count1, number;
vector<int> v;

void operation(int y, int x, int number){
    //cout << "operation called"<<endl;
    for(int i=0; i<4; i++){
        int routeY = y + rangeY[i];
        int routeX = x + rangeX[i];
        
        if(0<=routeX&&routeX<=24 && 0<=routeY&&routeY<=24 && visited[routeY][routeX]==0 && table[routeY][routeX]==1 ){
            visited[routeY][routeX]=1;
            v.back()++;
            operation(routeY, routeX, number+1);
        }
    }
}

int main(){
    int N;
    cin >> N;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%1d",&table[i][j]);
        }
    }
    //cout<< "cin completed"<<endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(visited[i][j]==0 && table[i][j]==1){
                //cout<<"condition called"<<endl;
                visited[i][j]=1;
                count1++;
                v.push_back(1);
                operation(i,j,0);
            }
        }
    }
    cout<<count1<<endl;
    sort(v.begin(), v.end());
    for(auto& x : v)
        cout<<x<<endl;
    return 0;
}
