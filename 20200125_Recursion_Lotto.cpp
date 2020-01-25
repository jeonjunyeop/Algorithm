// 로또 _ 정올2817
//  20200125_Recursion_Lotto.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 1/25/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int K;
string usableNum[13];

void lotto(int num, string answer, int count){

    if(count == 6){
        for(auto& x : answer){
            cout << x;
        }cout<<endl;
        return;
    }

    for(int i = num; i<K; i++)
        lotto(i+1, answer+usableNum[i]+' ', count+1);
}

int main (){
    cin >> K;
    for(int i=0; i<K; i++)
        cin >> usableNum[i];
    lotto(0,"",0);
    return 0;
}// 2MB 12ms

//int K;
//int usableNum[13];
//int combination[6];
//void lotto(int num, int count){
//
//    if(count == 6){
//        for(auto& x : combination){
//            cout << x<<" ";
//        }cout<<endl;
//        return;
//    }
//
//    for(int i = num; i<K; i++){
//        combination[count] = usableNum[i];
//        lotto(i+1, count+1);
//    }
//}
//
//int main (){
//    cin >> K;
//    for(int i=0; i<K; i++){
//        cin >> usableNum[i];
//    }
//    lotto(0,0);
//    return 0;
//} 2MB 16ms
