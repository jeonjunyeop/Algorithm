// 백준 1717_ 집합의 표현
//  20201006_Union-find_Express union.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 10/6/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int table[1000000];

int get_parent(int a){
    if(table[a] == a)
        return a;
    else
        return table[a] = get_parent(table[a]);
}

void merge_parent(int a, int b){
    a = get_parent(a);
    b = get_parent(b);
    if(a < b)
        table[b] = a;
    else if(a > b)
        table[a] = b;
}

void find_parent(int a , int b){
    a = get_parent(a);
    b = get_parent(b);
    if(a == b)
        cout << "YES\n";
    else
        cout << "NO\n";
}


void initialization(int n){
    for(int i=0; i<=n; i++)
        table[i] = i;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    initialization(n);
    
    bool mergeORquestion;
    int a, b;
    for(int i=0; i<m; i++){
        cin >> mergeORquestion >> a >> b;
        if(mergeORquestion==0) // Merge
            merge_parent(a, b);
        else // Ask if 'a' and 'b' have a same parent.
            find_parent(a, b);
    }
    
    return 0;
}
