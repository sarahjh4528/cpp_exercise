#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    int climbStairs(int n) {
        /* In theory this is to find all non duplicated permutations.
         * turn out this is actually testing fibonacci sequence.
         * The best way to implement fibonacci number is to use
         * dynamic programming.
         *  1 solution for 1 stair: 1
         *  2 solution for 2 stairs: 1 1, 2
         *  3 solution for 3 stairs: 1 1 1, 2 1, 1 2
         *  5 solution for 4 stairs: 1 1 1 1, 2 1 1, 1 2 1, 1 1 2, 2 2
         * f(n) = f(n-1) + f(n-2)
         */
        if (n < 3)
            return n;

        vector<int> dp(n+1);
        dp[1] = 1;    // If only one stair, there is only one solution: 1
        dp[2] = 2;    // 2 solution for 2 stairs: 1 1, 2
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

int main() {
#if 0
    int stairs = 3;
    int stairs = 5;
    int stairs = 1;
#endif
    int stairs = 2;

    Solution s;
    int output = s.climbStairs(stairs);
    cout << "stairs: " << stairs << ", # of ways: " << output << endl;
    return 0;
}
