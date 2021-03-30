// LEETCODE
//  20210330_Array_Best Time to Buy and Sell Stock II.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 3/30/21.
//  Copyright © 2021 Junyeop Jeon. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// MARK: - EXAMPLE
/*You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e., max profit = 0.
*/

// MARK: - SOLUTION
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int answer = 0;
        int len = prices.size();
        int a = prices[0];
        for(int i=1; i<len; i++)
        {
            if( a >= prices[i] )
            {
            }
            else
            {
                int profit = prices[i] - a;
                answer += profit;
            }
            a = prices[i];
        }
        return answer;
    }
};

void testCaseRun(vector<int>v, int result)
{
    Solution sol;
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i]<<",";
    }
    cout << "  "<<result<<"\n";
    if(sol.maxProfit(v) == result)
    {
        cout << "Correct Answer.\n";
    }
    else{
        cout << "Wrong Answer! Please review the Solution.\n";
    }
    cout <<"\n";
}

int main()
{
    testCaseRun({7,1,5,3,6,4}, 7);
    testCaseRun({1,2,3,4,5}, 4);
    testCaseRun({7,6,4,3,1}, 0);
    
    return 0;
}
/*
 200 / 200 test cases passed.
Status: Accepted
Runtime: 4 ms
Memory Usage: 12.9 MB
 */
