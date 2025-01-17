#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

/*
1 <= nums.length <= 10^5
nums[i] is either 0 or 1.
*/
    int longestSubarray(vector<int>& nums) {
    }
};

int main()
{
    vector<vector<int>> vnums = {
        {1,1,0,1},
        {0,1,1,1,0,1,1,0,1},
        {1,1,1}
    };
    Solution s;

    for (auto nums : vnums) {
        s.printVec(nums);
        int output = s.longestSubarray(nums);
        cout << "Num of longest subarry 1 after rm one element: " << output << endl;
    }
    return 0;
}
