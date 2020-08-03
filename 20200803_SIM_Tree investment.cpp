//
//  20200803_SIM_Tree investment.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 8/3/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
//Initial table N*N
//M Trees
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int dir[8][2] = {{0,1},{1,0},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    int n,m,k;
    int nu[10][10];
    int add[10][10];
    vector<int> tree[10][10];
    
    cin >> n >> m >> k;
    
    //Initial nourishment 5
   
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            nu[i][j] = 5;
            cin >> add[i][j];
        }
    
    int x, y, z;
    for(int i=0; i<m; i++){
        cin >> x >> y >> z;
        tree[x-1][y-1].push_back(z);
    }
    while(k--){
        //*Spring: Trees absorb nourishment as its age, and +1  ------------
        // younger one first
        // Not enough -> die
        
//        //print
//        cout << "season start\n";
//        for(int i=0; i<n; i++){
//            for(int j=0; j<n; j++){
//                cout <<nu[i][j]<<" ";
//            }cout <<"\n";
//        }
        //*Summer: Dead tree -> age/2 as nutrition--------------------------
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int size = tree[i][j].size();
                if(size!=0){
                    sort(tree[i][j].begin(), tree[i][j].end());
                    vector<int> temp(0);
                    int dead_tree=0;
                    for(int v=0; v<size; v++){
                        int value = tree[i][j][v];
                        if(nu[i][j]>=value){
                            nu[i][j] -= value;
                            temp.push_back(value+1);
                        }else{
                            dead_tree += value/2;
                        }
                    }
                    nu[i][j] += dead_tree;
                    tree[i][j].clear();
                    for(auto& x : temp){
                        tree[i][j].push_back(x);
                    }
                }
                
            }
        }
        //------------------------------------------------------------------

//        //Print
//        for(int i=0; i<n; i++){
//            for(int j=0; j<n; j++){
//                if(tree[i][j].size()==0){
//                    cout<<"(0) ";
//                }else{
//                    cout <<"(";
//                    for(int v=0; v<tree[i][j].size(); v++){
//                        cout << tree[i][j][v]<<",";
//                    }
//                    cout <<") ";
//                }
//            }cout <<"\n";
//        }cout <<"\n";
        
        //------------------------------------------------------------------
        //*Fall: 5x can propagate to 8 direction as age 1
        vector<pair<int, int>> children(0);
        for(int i=0; i<n; i++){
            for (int j=0; j<n; j++) {
                if(tree[i][j].size()){
                    for(int v=0; v<tree[i][j].size(); v++){
                        if(tree[i][j][v]%5 == 0){
    //                        cout <<i<<","<<j<<"!\n";
                            for(int t=0; t<8; t++){
                                int y = i + dir[t][0];
                                int x = j + dir[t][1];
                                if(0<=y&&y<n && 0<=x&&x<n){
                                    tree[y][x].push_back(1);
                                    //children.push_back({y,x});
                                }
                            }
                        }
                    }
                }
            }
        }

        //------------------------------------------------------------------
        //*Winter: Add nutrition as provided table
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                nu[i][j] += add[i][j];
            }
        }
        
//        //print
//        for(int i=0; i<n; i++){
//            for(int j=0; j<n; j++){
//                if(tree[i][j].size()==0){
//                    cout<<"(0) ";
//                }else{
//                    cout <<"(";
//                    for(int v=0; v<tree[i][j].size(); v++){
//                        cout << tree[i][j][v]<<",";
//                    }
//                    cout <<") ";
//                }
//            }cout <<"\n";
//        }cout <<"\n";
        
    } // while(k--)
    
    int cnt=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
                cnt += tree[i][j].size();

    cout << cnt<<"\n";
    return 0;
}
