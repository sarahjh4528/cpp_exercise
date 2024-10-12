#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> wSet(wordDict.begin(), wordDict.end());
        int strLen = s.length();
        vector<bool> dp(strLen+1, false);
        dp[0] = true;

        for (int i = 1; i <= strLen; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (dp[j] && wSet.find(s.substr(j, i-j)) != wSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[strLen];
    }
};

int main()
{
    vector<string> words = {
        "leetcode",
        "applepenapple",
        "catsandog",
    };
    vector<vector<string>> wordDicts = {
        {"leet", "code"},
        {"apple", "pen"},
        {"cats", "dog", "sand", "and", "cat"},
    };

    Solution s;
    for (int i = 0; i < 3; ++i) {
        bool wordInDict = s.wordBreak(words[i], wordDicts[i]);
        cout << "Word in Dict : " << wordInDict << endl;
    }
    return 0;
}
