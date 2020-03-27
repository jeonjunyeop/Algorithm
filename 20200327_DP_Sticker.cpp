// Sticker (백준9456스티커)
//  20200327_DP_Sticker.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 3/27/20.
//  Copyright © 2020 Junyeop Jeon. All rights reserved.
//
/*Nancy, your little sister, has a sheet of 2n stickers of rectangular shape that are arranged in 2 rows and n columns. See Figure 1(a). Nancy wants to decorate her desk with the stickers. But the quality of the stickers is poor, and tearing off one sticker from the sheet spoils the stickers sharing an edge with it. So, Nancy must lose the stickers above, below, to the left of, and to the right of the sticker she tears off.


Nancy had no idea about what to do. You looked at her and suggested that she should score each sticker and try to choose a possible set of stickers that maximizes the total score. Nancy marked scores to all the 2n stickers as in Figure 1(b). And Nancy had no idea, again. You again took a look at her and sighed. You cannot help doing something for her, and at last decided to help her with a fast computer program. Your program is to select a set of stickers of maximum total score from the 2n stickers such that no two of them share an edge.

In the example shown in Figure 1, the maximum total score is 260 when you select the four stickers of scores 50, 50, 100, 60. Unfortunately, in this case, it is not allowed to simultaneously select both of the two highest scored stickers (of score 100 and 70) because the two stickers share an edge between them.

Input:
Your program is to read from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Each test case starts with a line that contains an integer (1 ≤ n ≤ 100,000), where 2n is the number of stickers in the sheet. In the next two lines, each line contains n integers, each of which represents Nancy’s score for the sticker at that position in the sticker sheet. Every two consecutive integers in a line are separated by a blank. Note that the 2n stickers are of rectangular shape and are arranged in 2 rows and n columns in the sheet. Nancy’s scores range from 0 to 100.

Output:
Your program is to write to standard output. Print exactly one line for each test case. The line should contain the maximum possible total score for a subset of the 2n stickers such that no two stickers share an edge.*/
#include <iostream>
#include <algorithm>
using namespace std;
int T,n;
int table[2][100000];
int dp[2][100000];
void solution(){
    for(int i=2; i<=n; i++){
        dp[0][i] = max(dp[1][i-1], dp[1][i-2])+table[0][i];
        dp[1][i] = max(dp[0][i-1], dp[0][i-2])+table[1][i];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for(int i=0 ;i<T; i++){
        cin >> n;
        for(int j=1; j<=n; j++){
            cin >> table[0][j];
        }
        for(int j=1; j<=n; j++){
            cin >> table[1][j] ;
        }
        dp[0][1] = table[0][1];
        dp[1][1] = table[1][1];
        solution();
        cout << max(dp[0][n],dp[1][n])<<"\n";
//        for(int k=0; k<=n; k++){
//            cout << dp[0][k] << " ";
//        }cout <<"\n";
//        for(int k=0; k<=n; k++){
//            cout << dp[1][k] << " ";
//        }cout <<"\n";
    }
    return 0;
}
