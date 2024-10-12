#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p) {
        int sLen = s.length(), pLen = p.length();
        vector<vector<bool>> dp(sLen + 1, vector<bool>(pLen + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= sLen; ++i) {
            for (int j = 1; j <= pLen; ++j) {
                if (p[j-1] == '*') {
                    // First char of p is guaranteed not a '*' due to following statement.
                    // '*' Matches zero or more of the preceding element.
                    dp[i][j] = dp[i][j-2] ||
                               (i > 0 && dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.')); //char* or .*
                } else {
                    dp[i][j] = i > 0 && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                }
            }
        }
        return dp[sLen][pLen];
    }
};

int main()
{
    vector<string> vsStr = {
        "aa",
        "aa",
        "ab",
        "aab",
        "aaca",
        "aaba",
        "aaa",
    };
    vector<string> vpStr = {
        "a",
        "a*",
        ".*",
        "c*a*b",
        "ab*a*c*a",
        "ab*a*c*a",
        "ab*a*c*a",
    };

    Solution s;
    for (int i = 0; i < vsStr.size(); ++i) {
        bool matchRet = s.isMatch(vsStr[i], vpStr[i]);
        cout << vsStr[i] << " and " << vpStr[i] << endl;
        cout << "Match : " << matchRet << endl;
    }

    return 0;
}
