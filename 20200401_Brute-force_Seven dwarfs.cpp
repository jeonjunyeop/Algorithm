//  백준2309일곱 난쟁이
//  20200401_Brute-force_Seven dwarfs.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 4/1/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dwarf[10];
vector<int>v(0);
bool sign = true;
void operation(int idx, int sum){
    if(idx>9 || sum>100 || sign==false)
        return;
    if(v.size()==7 && sum==100){
        sort(v.begin(), v.end());
        for(int i=0; i<7; i++)
            cout << v[i]<<"\n";
        sign = false;
        return;
    }
    operation(idx+1, sum);
    v.push_back(dwarf[idx]);
    operation(idx+1, sum+dwarf[idx]);
    v.pop_back();
}

int main(){
    for(int i=0 ;i<9; i++)
        cin >> dwarf[i];
    operation(0, 0);
    return 0;
}
