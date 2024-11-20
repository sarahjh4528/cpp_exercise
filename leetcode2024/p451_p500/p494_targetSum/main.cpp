/*
Runtime 11 ms Beats 63.45%
Memory 24.56 MB Beats 29.19%
*/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
    int solve(vector<int>& nums, int target, int i, int cur, int ioffset, vector<vector<int>>& dp) {
        if (i == nums.size())
            return (cur == target)? 1 : 0;
        int j = cur + ioffset;
        if (dp[i][j] != -1)
            return dp[i][j];
        int addnum = solve(nums, target, i+1, cur+nums[i], ioffset, dp);
        int subnum = solve(nums, target, i+1, cur-nums[i], ioffset, dp);
        dp[i][j] = addnum + subnum;
        return dp[i][j];
    }
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n, vector<int>(2*sum+1, -1));
        return solve(nums, target, 0, 0, sum, dp);
    }
};

int main()
{
    vector<vector<int>> vnums = {
        {1,1,1,1,1},
        {1}
    };
    vector<int> vt = {3,1};
    Solution s;

    for (int i = 0; i < vt.size(); i++) {
        s.printVec(vnums[i]);
        int output = s.findTargetSumWays(vnums[i], vt[i]);
        cout << "Number of ways to form target " << vt[i] << " : " << output << endl;
    }
    return 0;
}
