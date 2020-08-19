// CUBING 백준5373
//  20200819_SIM_Cubing.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 8/19/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
/*A Rubik’s Cube is a three-dimensional puzzle. In its original version, it is made up of 3×3×3 smaller cubes. Each of the visible faces of these smaller cubes has one of six colors (white, yellow, red, orange, green or blue). A Rubik’s Cube is said to be solved if on each face, the nine cubes all show the same color.

The Cube is mechanically constructed such that it is possible to rotate any face (that is, any set of 3×3 smaller cubes making up one of the six faces of the entire cube) by 90 degrees in both directions. When a rotation is completed, it is again possible to rotate any face in any direction. Thus by combining rotations performed on different faces, it is possible to mix up the colors. The puzzle is then to take a Cube whose colors are mixed up, and return it to its solved state.

We start from a solved Rubik’s Cube, which is completely white on the top (up) face, yellow on the bottom (down), red on the front, orange on the back, green on the left and blue on the right. You are given a sequence of rotations. Determine what the top face looks like after applying all rotations.



A solved Rubik’s Cube. In the left image the top (white), front (red) and left (green) face are shown. In the right image the same cube is viewed from the opposite side, with the bottom (yellow), back (orange) and right (blue) face visible. Shown is the way in which a face can be rotated (in this case, the left face is partially rotated clockwise).

INPUT
On the ﬁrst line one positive number: the number of test cases, at most 100. After that per test case:

one line with an integer n (1 ≤ n ≤ 1 000): the number of rotations.
one line with n space-separated pairs of characters: the rotations. For each rotation, the ﬁrst character identiﬁes the face that is rotated: ‘U’ for the top (up) face, ‘D’ for the bottom (down), ‘F’ for the front, ‘B’ for the back, ‘L’ for the left and ‘R’ for the right. The second character indicates the direction of the rotation: ‘+’ for a clockwise rotation (when looking directly at the face that is rotated), ‘-’ for a counterclockwise rotation.
OUTPUT
Per test case:

three lines, each with three characters: the colors of the squares on the top face of the cube, after applying the rotations. The ﬁrst line corresponds to the squares adjacent to the back side of the cube. The colors are indicated by the ﬁrst letter (lower case): ‘w’ for white, ‘y’ for yellow, ‘r’ for red, ‘o’ for orange, ‘g’ for green and ‘b’ for blue.*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
char table[6][3][3];

void rotation(char direction, int surface, char temp[][3][3]){
    if(direction == '+'){
        temp[surface][0][0] = table[surface][2][0];
        temp[surface][0][1] = table[surface][1][0];
        
        temp[surface][0][2] = table[surface][0][0];
        temp[surface][1][2] = table[surface][0][1];
        
        temp[surface][2][2] = table[surface][0][2];
        temp[surface][2][1] = table[surface][1][2];
        
        temp[surface][2][0] = table[surface][2][2];
        temp[surface][1][0] = table[surface][2][1];
    }else{
        temp[surface][0][0] = table[surface][0][2];
        temp[surface][0][1] = table[surface][1][2];
        
        temp[surface][0][2] = table[surface][2][2];
        temp[surface][1][2] = table[surface][2][1];
        
        temp[surface][2][2] = table[surface][2][0];
        temp[surface][2][1] = table[surface][1][0];
        
        temp[surface][2][0] = table[surface][0][0];
        temp[surface][1][0] = table[surface][0][1];
    }
    
}

void initialization(){
    char cell;
    for(int i=0; i<6; i++){
        if(i==0) // Upper side
            cell = 'w';
        else if(i==1) // Down side
            cell = 'y';
        else if(i==2) // Front side
            cell = 'r';
        else if(i==3) // Back side
            cell = 'o';
        else if(i==4) // Left side
            cell = 'g';
        else // Right side
            cell = 'b';
        
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                table[i][j][k] = cell;
            }
        }
    }
}

void simulation(vector<pair<char, char>>vec){
    
    char temp[6][3][3];
    
    for(int i=0; i<vec.size(); i++){
        memset(temp, ' ', sizeof(temp));
        char side = vec[i].first;
        char direction = vec[i].second;
        if(side == 'U'){
            if(direction == '+'){
                temp[2][0][0] = table[5][2][0];
                temp[2][0][1] = table[5][1][0];
                temp[2][0][2] = table[5][0][0];
                
                temp[4][0][2] = table[2][0][0];
                temp[4][1][2] = table[2][0][1];
                temp[4][2][2] = table[2][0][2];
                
                temp[3][0][0] = table[4][0][2];
                temp[3][0][1] = table[4][1][2];
                temp[3][0][2] = table[4][2][2];
                
                temp[5][2][0] = table[3][0][0];
                temp[5][1][0] = table[3][0][1];
                temp[5][0][0] = table[3][0][2];
                
                rotation('+', 0, temp);
            
            }else{
                temp[5][2][0] = table[2][0][0];
                temp[5][1][0] = table[2][0][1];
                temp[5][0][0] = table[2][0][2];
                
                temp[2][0][0] = table[4][0][2];
                temp[2][0][1] = table[4][1][2];
                temp[2][0][2] = table[4][2][2];
                
                temp[4][0][2] = table[3][0][0];
                temp[4][1][2] = table[3][0][1];
                temp[4][2][2] = table[3][0][2];
                
                temp[3][0][0] = table[5][2][0];
                temp[3][0][1] = table[5][1][0];
                temp[3][0][2] = table[5][0][0];
                
                rotation('-', 0, temp);
            }
        }else if(side == 'D'){
            if(direction == '+'){
                temp[5][2][2] = table[2][2][0];
                temp[5][1][2] = table[2][2][1];
                temp[5][0][2] = table[2][2][2];
                
                temp[2][2][0] = table[4][0][0];
                temp[2][2][1] = table[4][1][0];
                temp[2][2][2] = table[4][2][0];
                
                temp[4][0][0] = table[3][2][0];
                temp[4][1][0] = table[3][2][1];
                temp[4][2][0] = table[3][2][2];
                
                temp[3][2][0] = table[5][2][2];
                temp[3][2][1] = table[5][1][2];
                temp[3][2][2] = table[5][0][2];
                
                rotation('+', 1, temp);
            }else{
                temp[2][2][0] = table[5][2][2];
                temp[2][2][1] = table[5][1][2];
                temp[2][2][2] = table[5][0][2];
                
                temp[4][0][0] = table[2][2][0];
                temp[4][1][0] = table[2][2][1];
                temp[4][2][0] = table[2][2][2];
                
                temp[3][2][0] = table[4][0][0];
                temp[3][2][1] = table[4][1][0];
                temp[3][2][2] = table[4][2][0];
                
                temp[5][2][2] = table[3][2][0];
                temp[5][1][2] = table[3][2][1];
                temp[5][0][2] = table[3][2][2];
                
                rotation('-', 1, temp);
            }
        }else if(side == 'F'){
            if(direction == '+'){
                temp[1][2][2] = table[5][2][2];
                temp[1][2][1] = table[5][2][1];
                temp[1][2][0] = table[5][2][0];
                
                temp[4][2][2] = table[1][2][2];
                temp[4][2][1] = table[1][2][1];
                temp[4][2][0] = table[1][2][0];
                
                temp[0][2][2] = table[4][2][2];
                temp[0][2][1] = table[4][2][1];
                temp[0][2][0] = table[4][2][0];
                
                temp[5][2][2] = table[0][2][2];
                temp[5][2][1] = table[0][2][1];
                temp[5][2][0] = table[0][2][0];
                
                rotation('+', 2, temp);
            }else{
                temp[5][2][2] = table[1][2][2];
                temp[5][2][1] = table[1][2][1];
                temp[5][2][0] = table[1][2][0];
                
                temp[1][2][2] = table[4][2][2];
                temp[1][2][1] = table[4][2][1];
                temp[1][2][0] = table[4][2][0];
                
                temp[4][2][2] = table[0][2][2];
                temp[4][2][1] = table[0][2][1];
                temp[4][2][0] = table[0][2][0];
                
                temp[0][2][2] = table[5][2][2];
                temp[0][2][1] = table[5][2][1];
                temp[0][2][0] = table[5][2][0];
                
                rotation('-', 2, temp);
            }
        }else if(side == 'B'){
            if(direction == '+'){
                temp[5][0][2] = table[1][0][2];
                temp[5][0][1] = table[1][0][1];
                temp[5][0][0] = table[1][0][0];
                
                temp[1][0][2] = table[4][0][2];
                temp[1][0][1] = table[4][0][1];
                temp[1][0][0] = table[4][0][0];
                
                temp[4][0][2] = table[0][0][2];
                temp[4][0][1] = table[0][0][1];
                temp[4][0][0] = table[0][0][0];
                
                temp[0][0][2] = table[5][0][2];
                temp[0][0][1] = table[5][0][1];
                temp[0][0][0] = table[5][0][0];
                
                rotation('+', 3, temp);
            }else{
                temp[1][0][2] = table[5][0][2];
                temp[1][0][1] = table[5][0][1];
                temp[1][0][0] = table[5][0][0];
                
                temp[4][0][2] = table[1][0][2];
                temp[4][0][1] = table[1][0][1];
                temp[4][0][0] = table[1][0][0];
                
                temp[0][0][2] = table[4][0][2];
                temp[0][0][1] = table[4][0][1];
                temp[0][0][0] = table[4][0][0];
                
                temp[5][0][2] = table[0][0][2];
                temp[5][0][1] = table[0][0][1];
                temp[5][0][0] = table[0][0][0];
                
                rotation('-', 3, temp);
            }
        }else if(side == 'L'){
            if(direction == '+'){
                temp[2][0][0] = table[0][0][0];
                temp[2][1][0] = table[0][1][0];
                temp[2][2][0] = table[0][2][0];
                
                temp[0][0][0] = table[3][2][2];
                temp[0][1][0] = table[3][1][2];
                temp[0][2][0] = table[3][0][2];
                
                temp[3][2][2] = table[1][2][2];
                temp[3][1][2] = table[1][1][2];
                temp[3][0][2] = table[1][0][2];
                
                temp[1][2][2] = table[2][0][0];
                temp[1][1][2] = table[2][1][0];
                temp[1][0][2] = table[2][2][0];
                
                rotation('+', 4, temp);
            }else{
                temp[0][0][0] = table[2][0][0];
                temp[0][1][0] = table[2][1][0];
                temp[0][2][0] = table[2][2][0];
                
                temp[3][2][2] = table[0][0][0];
                temp[3][1][2] = table[0][1][0];
                temp[3][0][2] = table[0][2][0];
                
                temp[1][2][2] = table[3][2][2];
                temp[1][1][2] = table[3][1][2];
                temp[1][0][2] = table[3][0][2];
                
                temp[2][0][0] = table[1][2][2];
                temp[2][1][0] = table[1][1][2];
                temp[2][2][0] = table[1][0][2];
                
                rotation('-', 4, temp);
            }
        }else if(side == 'R'){
            if(direction == '+'){
                temp[3][0][0] = table[0][2][2];
                temp[3][1][0] = table[0][1][2];
                temp[3][2][0] = table[0][0][2];
                
                temp[0][2][2] = table[2][2][2];
                temp[0][1][2] = table[2][1][2];
                temp[0][0][2] = table[2][0][2];
                
                temp[2][2][2] = table[1][0][0];
                temp[2][1][2] = table[1][1][0];
                temp[2][0][2] = table[1][2][0];
                
                temp[1][0][0] = table[3][0][0];
                temp[1][1][0] = table[3][1][0];
                temp[1][2][0] = table[3][2][0];
                
                rotation('+', 5, temp);
            }else{
                temp[3][0][0] = table[1][0][0];
                temp[3][1][0] = table[1][1][0];
                temp[3][2][0] = table[1][2][0];
                
                temp[1][0][0] = table[2][2][2];
                temp[1][1][0] = table[2][1][2];
                temp[1][2][0] = table[2][0][2];
                
                temp[2][2][2] = table[0][2][2];
                temp[2][1][2] = table[0][1][2];
                temp[2][0][2] = table[0][0][2];
                
                temp[0][2][2] = table[3][0][0];
                temp[0][1][2] = table[3][1][0];
                temp[0][0][2] = table[3][2][0];
                
                rotation('-', 5, temp);
            }
        }else{
            //cout << side<<"\n";
            cout<<"Exception\n";
        }
        
        //Exchange
        for(int j=0; j<=5; j++){
            for(int k=0; k<=2; k++){
                for(int l=0; l<=2; l++){
                    if(temp[j][k][l]!=' '){
                        table[j][k][l] = temp[j][k][l];
                    }
                }
            }
        }
//        for(int i=0; i<3; i++){
//            for(int j=0; j<3; j++){
//                cout << table[0][i][j];
//            }cout << "\n";
//        }cout <<"\n";
    }
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << table[0][i][j];
        }cout << "\n";
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T,n;
    cin >> T;
    while (T--) {
        initialization();
        
        cin >> n;
        vector<pair<char, char>>v(0);
        char a,b;
        for(int i=0; i<n; i++){
            cin >> a >> b;
            v.push_back({a,b});
        }
        simulation(v);
        v.clear();
    }
    
    return 0;
}
