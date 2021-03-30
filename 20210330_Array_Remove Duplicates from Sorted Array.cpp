//
//  20210330_Array_Remove Duplicates from Sorted Array.cpp
//  algorithm tests
//
//  Created by Junyeop Jeon on 3/30/21.
//  Copyright © 2021 Junyeop Jeon. All rights reserved.
// LeetCode
#include <iostream>
#include <vector>

using namespace std;


// MARK: - CLARIFICATION
// nums is passed in by reference. (i.e., without making a copy)
//int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
//for (int i = 0; i < len; i++) {
//    print(nums[i]);
//}


// MARK: - EXAMPLE
//Example 1:
//
//Input: nums = [1,1,2]
//Output: 2, nums = [1,2]
//Explanation: Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the returned length.
//Example 2:
//
//Input: nums = [0,0,1,1,1,2,2,3,3,4]
//Output: 5, nums = [0,1,2,3,4]
//Explanation: Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively. It doesn't matter what values are set beyond the returned length.
 

// MARK: - SOLUTION
class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {

        int len = nums.size();
        if ( 0 == len || 1 == len )
        {
            
        }
        else
        {
            int a = nums[0];
            int i = 1;
            
            while(1)
            {
                if( a == nums[i] )
                {
                    nums.erase(nums.begin()+i);
                    len--;
                }
                else
                {
                    a = nums[i];
                    i++;
                }
                
                if( i == len)
                {
                    break;
                }
                
            } // while
            
        }
        return len;
    }
};

int main()
{
    vector<int> inputVector = {1,1};
    
    Solution sol;
    sol.removeDuplicates(inputVector);
    
    for(int i=0; i<inputVector.size(); i++)
    {
        cout << inputVector[i] <<" ";
    }cout <<"\n";
    cout << inputVector.size()<<"\n";
    return 0;
}


//161 / 161 test cases passed.
//Status: Accepted
//Runtime: 136 ms
//Memory Usage: 13.6 MB
