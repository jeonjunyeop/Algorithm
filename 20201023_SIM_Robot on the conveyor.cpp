//
//  20201023_SIM_Robot on the conveyor.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 10/23/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
// 백준 20055 컨베이어 벨트 위의 로봇
#include <iostream>
using namespace std;
int table[200];
bool worker[200];

bool finish(int n, int k){
    int cnt = 0;
    for(int i=0; i<n*2; i++)
         if(table[i]==0)
             cnt++;
    if(cnt>=k)
        return true;
    else
        return false;
}

int main(){
    int n, k;
    cin >> n >> k;
    for(int i=0; i<n*2; i++){
        cin >>table[i];
        worker[i] = false;
    }
    
    int stage=0;
    
    while (finish(n, k)==false) {
         // -- ROTATION --
           int copy_table[200];
           bool copy_worker[200];
           for(int i=0; i<n*2; i++){
               copy_table[i] = 0;
               copy_worker[i] = 0;
           }
           
           for(int i=n-1; i>0; i--){
               copy_worker[i] = worker[i-1];
           }
           for(int i=2*n-1; i>0; i--){
               copy_table[i] = table[i-1];
           }
           copy_table[0] = table[2*n-1];
           for(int i=0; i<n; i++){
               worker[i] = copy_worker[i];
           }
           for(int i=0; i<n*2; i++){
               table[i] = copy_table[i];
           }
           
           // Arrived
            if(worker[n-1]==true)
                worker[n-1] = false;
        // -- MOVE --
           for(int i=n-2; i>=0; i--){
               if(worker[i]==true){
                   if(worker[i+1]==false && table[i+1]>0){
                       worker[i]=false;
                       worker[i+1] = true;
                       table[i+1]--;
                   }
               }
           }
           if(worker[0]==false && table[0]>0){
               worker[0] = true;
               table[0]--;
           }
        stage++;
    }
    cout << stage<<"\n";
   
    return 0;
}
