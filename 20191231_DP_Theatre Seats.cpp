// 극장 좌석 _ 정올1848
//  20191231_DP_Theatre Seats.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 12/31/19.
//  Copyright © 2019 Junyeop Jeon. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main(){
    int answer=1;
    int vsize,stn,temp,k=0;
    unordered_set<int> s;
    vector<int> v;
    
    cin>> vsize;
    
    cin >> stn;
    for(int i=0; i<stn; i++){
        cin >> temp;
        s.insert(temp);
    }
   
    v.push_back(1);
    v.push_back(2);
    for(int i=2; i<vsize; i++)
        v[i] = v[i-1] +v[i-2];
    
    for(int i=1; i<=vsize; i++){
        if(s.count(i)>0&&k!=0){
            answer*=v[k-1];
            k=0;
        }else if(s.count(i)>0&&k==0){
            continue;
        }else{
            k++;
        }
    }
    if(k>0)
        answer*=v[k-1];
    cout<<answer<<endl;
    
    return 0;
}
