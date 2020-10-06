// 백준1976 여행가자
//  20201006_Union-Find_Let's go trip.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 10/6/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int table[201];

int get_parent(int a){
    if(table[a] == a)
        return a;
    else
        return table[a] = get_parent(table[a]);
    
}

void union_parent(int a , int b){
    a = get_parent(a);
    b = get_parent(b);
    if(a<b){
        table[b] = a;
    }else if(a>b){
        table[a] = b;
    }
}

int find_parent(int a, int b){
    a = get_parent(a);
    b = get_parent(b);
    if(a==b){
        return 1;
    }else{
        return 0;
    }
}

void initialization(int n){
    for(int i=0;i<=n; i++)
        table[i]=i;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; // Cities
    int m; // Plan
    cin >> n >> m;
    initialization(n);
    
    int temp;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> temp;
            if(i<j && temp==1){
                union_parent(i, j);
            }
        }
    }
    vector<int> v;
    for(int i=0; i<m; i++){
        cin >> temp;
        v.push_back(temp);
    }
    for(int i=1; i<v.size(); i++){
        int source = v[i-1];
        int destination = v[i];
        if(find_parent(source, destination)==0){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
