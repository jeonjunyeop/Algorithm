//  N 과 M 1~12 백준15649~15666
//  20200415_Brute-force_N&M 1~12.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 4/15/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
int N,M;
vector<int> v(0);
int visited[9];
int arr[8];
int cnt[9];
vector<int> initial_number(0);
unordered_set<int> s;

void nm1(int num){
    if(v.size()==M){
        for(int i=0; i<v.size(); i++)
            cout <<v[i]<<" ";
        cout <<"\n";
        return;
    }
    if(num>N)
        return;

    for(int i=1; i<=N; i++){
        if(visited[i]==0){
            visited[i]=1;
            v.push_back(i);
            nm1(i);
            visited[i]=0;
            v.pop_back();
        }
    }
}

void nm2(int num){
    if(v.size()==M){
        for(int i=0; i<v.size(); i++)
            cout <<v[i]<<" ";
        cout <<"\n";
        return;
    }
    if(num>N)
        return;

    v.push_back(num);
    nm2(num+1);
    v.pop_back();
    nm2(num+1);
}

void nm3(int num){
    if(v.size()==M){
        for(int i=0; i<v.size(); i++)
            cout <<v[i]<<" ";
        cout <<"\n";
        return;
    }
    if(num>N)
        return;

    for(int i=1; i<=N; i++){
        v.push_back(i);
        nm3(i);
        v.pop_back();
    }
}

void nm4(int num){
    if(v.size()==M){
        for(int i=0; i<v.size(); i++)
            cout <<v[i]<<" ";
        cout <<"\n";
        return;
    }
    if(num>N)
        return;

    for(int i=num; i<=N; i++){
        v.push_back(i);
        nm4(i);
        v.pop_back();
    }
}


void nm5(){ // RUN TIME ERROR
    if(v.size()==M){
        for(int i=0; i<v.size(); i++){
            cout << v[i]<<" ";
        }cout <<"\n";
        return;
    }

    for(int i=0; i<N; i++){
        if(visited[i]==0){
            visited[i]=1;
            v.push_back(arr[i]);
            nm5();
            visited[i]=0;
            v.pop_back();
        }
    }
}
void nm6(int idx){ // RUN TIME ERROR
    if(v.size()==M){
        for(int i=0; i<v.size(); i++){
            cout << v[i]<<" ";
        }cout <<"\n";
        return;
    }

    for(int i=idx; i<N; i++){
        if(visited[i]==0){
            visited[i]=1;
            v.push_back(arr[i]);
            nm6(i);
            visited[i]=0;
            v.pop_back();
        }
    }
}
void nm7(){ // RUN TIME ERROR
    if(v.size()==M){
        for(int i=0; i<v.size(); i++){
            cout << v[i]<<" ";
        }cout <<"\n";
        return;
    }

    for(int i=0; i<N; i++){
        v.push_back(arr[i]);
        nm7();
        v.pop_back();
    }
}

void nm8(int idx){ // RUN TIME ERROR
    if(v.size()==M){
        for(int i=0; i<v.size(); i++){
            cout << v[i]<<" ";
        }cout <<"\n";
        return;
    }

    for(int i=idx; i<N; i++){
        v.push_back(arr[i]);
        nm8(i);
        v.pop_back();
    }
}



void nm9(){
    if(v.size()==M){
        for(int i=0; i<v.size(); i++){
            cout << v[i]<<" ";
        }cout <<"\n";

        return;
    }

    for(int i=0; i<N; i++){
        int temp = initial_number[i];
        if(visited[temp]!=cnt[temp]){
            visited[temp]++;
            v.push_back(temp);
            nm9();
            visited[temp]--;
            v.pop_back();
        }
    }
}

void nm10(int idx){
    if(v.size()==M){
        for(int i=0; i<v.size(); i++){
            cout << v[i]<<" ";
        }cout <<"\n";
        return;
    }

    for(int i=idx; i<initial_number.size(); i++){
        int temp = initial_number[i];
        if(visited[temp]!=cnt[temp]){
            visited[temp]++;
            v.push_back(temp);
            nm10(i);
            visited[temp]--;
            v.pop_back();
        }
    }
}

void nm11(){
    if(v.size()==M){
        for(int i=0; i<v.size(); i++){
            cout << v[i]<<" ";
        }cout <<"\n";
        return;
    }

    for(int i=0; i<initial_number.size(); i++){
        int temp = initial_number[i];
       // if(visited[temp]!=cnt[temp]){
           // visited[temp]++;
            v.push_back(temp);
            nm11();
          //  visited[temp]--;
            v.pop_back();
       // }
    }
}
void nm12(int idx, int count){
   
    if(count==M){
        for(int i=0; i<M; i++){
            cout << initial_number[ arr[i]]<<" ";
        }cout <<"\n";
        return;
    }
    for(int i=idx; i<initial_number.size(); i++){
        arr[count] = i;
        nm12(i, count+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   
    cin >> N >>M;
//    nm1(1);
//    nm2(1);
//    nm3(1);
//    nm4(1);
//    for(int i=0; i<N;i++){
//        cin >>arr[i];
//    }
//    sort(arr, arr+N);
//    nm5();
//    nm6(0);
//    nm7();
//    nm8(0);
    
//    for(int i=0; i<N; i++){
//        int a;
//        cin >> a;
//        if(cnt[a]==0){
//            cnt[a]=1;
//            initial_number.push_back(a);
//        }
//        else{
//            cnt[a]++;
//        }
//    }
//    sort(initial_number.begin(), initial_number.end());
//    nm9();
//    nm10(0);
//    nm11();
    for(int i=0; i<N; i++){
            int a;
            cin >> a;
            if(s.count(a)==0){
                s.insert(a);
                initial_number.push_back(a);
            }
        }
    sort(initial_number.begin(), initial_number.end());
    nm12(0,0);
    return 0;
}
