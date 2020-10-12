//
//  20201012_SIM_Roullete Rotation.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 10/12/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//

// Roulette Rotation
// 백준 17822 원판 돌리기
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cstring>
using namespace std;
int n, m, t;
bool visited[52][51];
int dir[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};

bool bfs(int table[][51], int initial_y, int initial_x){
    bool deleted = false;
    queue<pair<int, int>> q;
    q.push({initial_y,initial_x});
    while (!q.empty()) {
        int ay = q.front().first;
        int ax = q.front().second;
        visited[ay][ax] = 1;
        q.pop();
        for(int i=0; i<4; i++){
            int y = ay + dir[i][0];
            int x = (ax + dir[i][1])%m;
            if(x==-1)
                x = m-1;
            
            if(0<=x&&x<m && 0<y&&y<=n &&visited[y][x]==0 && table[y][x]==table[initial_y][initial_x]){
                q.push({y,x});
                table[y][x] = 0;
                if(deleted == false)
                    deleted = true;
            }
        }
    }
    if(deleted==true){
        table[initial_y][initial_x] = 0;
        return true;
    }
    return false;
}

void neighbor_check(int table[][51]){
    bool erased = true;
    bool next_operation_required = true;
    double sum = 0;
    double num = 0;
    
    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++){
            if(table[i][j]!=0){
                if(visited[i][j]==0){
                    erased = bfs(table, i, j);
                    if(erased == true && next_operation_required == true){
                        next_operation_required = false;
                    }
                }
                num++;
                sum += table[i][j];
            }
        }
    }
    if(next_operation_required==true){
        double average = sum / num;
//        cout << sum <<"\n";
//        cout << num <<"\n";
//        cout << average<<"\n";
        for(int i=1; i<=n; i++){
            for(int j=0; j<m; j++){
                if(table[i][j]!=0){
                    if(table[i][j]>average){
                        --table[i][j];
                    }else if(table[i][j]<average){
                        ++table[i][j];
                    }
                }
            }
        }
    }
}
int total(int table[][51]){
    int result = 0;
    for(int i=1 ;i<=n; i++){
        for(int j=0; j<m; j++){
            if(table[i][j]>0){
                result += table[i][j];
            }
        }
    }
    return result;
}

int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
    int table[52][51];
    // -- INPUT ------------------------------
    cin >> n >> m >> t;
    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++){
            cin >> table[i][j];
        }
    }
    vector<pair<pair<int, int>, int>> rotate;
    int o,p,q;
    for(int i=0; i<t; i++){
    cin >> o >> p >> q;
        rotate.push_back({{o,p},q});
    }
    // ------------------------------ INPUT --
    
    // -- SIMULATION --------------------------------------
    for(int i=0; i<rotate.size(); i++){
        int base = rotate[i].first.first;
        int direction = rotate[i].first.second;
        int fortyfive = rotate[i].second;
        
        // - Rotate ------
        for(int j=1; j*base<=n; j++){
            int id = j*base;
            int arr[51];
            
            if(direction == 0){ // Clockwise
                for(int k=0; k<m; k++){
                    int next_idx = (k+fortyfive) % m;
                    arr[next_idx] = table[id][k];
                }
            }else{ // Reverse
                for(int k=0; k<m; k++){
                    int middle = m-(fortyfive%m);
                    int next_idx = (k+middle) % m;
                    arr[next_idx] = table[id][k];
                }
            }
            for(int k=0; k<m; k++){
                table[id][k] = arr[k];
            }
        }
        // ------------------------- --- Rotate --//
//        for(int i=1; i<=n; i++){
//            for(int j=0; j<m; j++){
//                cout << table[i][j]<<"|";
//            }cout <<"\n";
//        }cout <<"\n";
        // -- Erase number -------------------------
        if(total(table)==0){
            cout << 0 <<"\n";
            return 0;
        }
        memset(visited, 0, sizeof(visited));
        neighbor_check(table);
//        for(int i=1; i<=n; i++){
//            for(int j=0; j<m; j++){
//                cout << table[i][j]<<"|";
//            }cout <<"\n";
//        }cout <<"\n";
        
    }
    // ------------------------------------ SIMULATION -- //
    cout << total(table)<<"\n";

    return 0;
}
