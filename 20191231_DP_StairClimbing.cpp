// 계단 오르기_정올
//  20191231_DP_StairClimbing.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 12/31/19.
//  Copyright © 2019 Junyeop Jeon. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int answer=0;
    int num = 0;
     cin >> num;
    vector<int> stairs;
    
    vector<pair<int, int>> c;
    int ar[301][2];
    for(int i=0; i<num; i++){
        int temp;
        cin>>temp;
        stairs.push_back(temp);
    }
    ar[0][0]=stairs[0];
    ar[1][0]=stairs[0]+stairs[1];
    ar[0][1]=stairs[0];
    ar[1][1]=stairs[1];
    
    for(int i=2; i<num; i++){
        ar[i][0]=stairs[i]+ar[i-1][1];
        ar[i][1]=max(ar[i-2][0],ar[i-2][1])+stairs[i];
    }
    answer = max(ar[num-1][0], ar[num-1][1]);
    cout<<answer;
    
    return 0;
}
