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
0 <= n <= 37
The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.
*/
/*
Runtime 0 ms Beats 100.00%
Memory 8.37 MB Beats 32.53%
*/
    int tribonacci(int n) {
        if (n <= 2)
            return (n == 0)? 0 : 1;

        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for (int i = 3; i <= n; i++)
            dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
        
        return dp[n];
    }
};

int main()
{
    vector<int> vn = {4,25};
    Solution s;

    for (auto n : vn) {
        int output = s.tribonacci(n);
        cout << n << "th tribonacci num: " << output << endl;
    }
    return 0;
}
