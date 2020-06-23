//
//  20200623_Brute-force_Carpet.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 6/23/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int x = 1;
    int y = 1;
    for(x=1; x<brown; x++){
        y = (brown+4-(2*x))/2;
        if((x-2)*(y-2)==yellow)
            break;
    }
    answer.push_back(y);
    answer.push_back(x);
    return answer;
}
void assertion(int inbrown, int inyellow, vector<int> inresult){
    vector<int> answer = solution(inbrown, inyellow);
    if(answer == inresult){
        cout << "Correct answer.\n";
//        cout << answer<<"\n";
    }else{
        cout << "Wrong answer.\n";
//        cout << answer<<"\n";
    }
    
}
int main(){
    assertion(10, 2, {4,3});
    assertion(8, 1, {3,3});
    assertion(24, 24, {8,6});
   
    
    return 0;
}
