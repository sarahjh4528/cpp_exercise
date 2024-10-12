#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp{0};
        int m = dp.size();
        dp.resize(max(m, n+1), INT_MAX);
        for (int i1 = 1, i2; (i2 = i1*i1) <= n; ++i1) {
            for (int j = max(m, i2); j <= n; ++j) {
                cout << "j = " << j << ", dp[j] = " << dp[j] << endl;
                cout << "i2 = " << i2 << endl;
                if (dp[j] > dp[j-i2] + 1)
                    dp[j] = dp[j-i2] + 1;
            }
        }
        return dp[n];
    }
};

int main()
{
    vector<int> targets = {12, 13};
    Solution s;
    for (auto target : targets) {
        int numOfSq = s.numSquares(target);
        cout << numOfSq << endl;
    }
    return 0;
}
