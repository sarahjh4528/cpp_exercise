/*
Runtime 11 ms Beats 56.79%
Memory 16.31 MB Beats 58.67%
Time : O(nk) Space: O(nk)
*/
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

    int solve(int i, int op, int k, vector<int>& prices, vector<vector<int>>& dp) {
        if (i == prices.size())
            return 0;
        if (op > (k<<1))
            return 0;
        if (dp[i][op] != -1)
            return dp[i][op];

        int buyProfit = 0, sellProfit = 0;
        if (op % 2 == 0) {
            int buypft = solve(i+1, op+1, k, prices, dp) - prices[i];
            int skipbuy = solve(i+1, op, k, prices, dp);
            buyProfit = max(buypft, skipbuy);
        } else {
            int sellpft = solve(i+1, op+1, k, prices, dp) + prices[i];
            int skipsell = solve(i+1, op, k, prices, dp);
            sellProfit = max(sellpft, skipsell);
        }
        dp[i][op] = max(buyProfit, sellProfit);
        return dp[i][op];
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2*k+1, -1));
        return solve(0, 0, k, prices, dp);
    }
};

int main()
{
    vector<vector<int>> input = {
        {2,4,1},
        {3,2,6,5,0,3},
        {1,2,4,2,5,7,2,4,9,0}
    };
    vector<int> vk = {2, 2, 2};
    Solution s;

    for (int i = 0; i < vk.size(); i++) {
        s.printVec(input[i]);
        int output = s.maxProfit(vk[i], input[i]);
        cout << "Max profit with " << vk[i] << " transactions : " << output << endl;
    }

    return 0;
}
