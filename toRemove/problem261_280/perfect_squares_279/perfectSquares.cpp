#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        if (n == 1)
            return n;
        static vector<int> dp = {0};

        while (dp.size() <= n) {
            int m = dp.size();
            int squares = INT_MAX;
            for (int i = 1; i*i <= m; ++i) {
                squares = min(squares, dp[m-i*i] + 1);
                cout << i << ", dp[" << m-i*i << "] = " << dp[m-i*i] << endl;
            }
            dp.push_back(squares);
        }
        cout << dp.size() << endl;
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
