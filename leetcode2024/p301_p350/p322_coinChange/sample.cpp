/*
Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 2^31 - 1
0 <= amount <= 10^4
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

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= amount; i++) {
            for (auto val : coins) {
                if (i >= val)
                    dp[i] = min(dp[i], 1+dp[i-val]);
            }
        }
        return (dp[amount] > amount)? -1 : dp[amount];
    }
};

int main()
{
    vector<vector<int>> vcoins = {
        {1,2,5},
        {2},
        {1},
        {474,83,404,3}
    };
    vector<int> vamount = {11,3,0,264};
    Solution s;

    for (int i = 0; i < vcoins.size(); i++) {
        s.printVec(vcoins[i]);
        int output = s.coinChange(vcoins[i], vamount[i]);
        cout << "Number of coins to form amount " << vamount[i] << " : " << output << endl;
        
    }
    vector<int> input = {1,2,3,4,5,6};
    return 0;
}
