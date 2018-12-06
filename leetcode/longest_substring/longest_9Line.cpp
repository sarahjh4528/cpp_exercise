#include<iostream>
#include<vector>

using namespace std;

#define LOOPSIZE 7
string sampleStr[LOOPSIZE] = {
"abcabcbb",
"bbbbb",
"pwwkew",
"",
" ",
"au",
"dvdf"
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};

int main()
{
    for (int i = 0; i < LOOPSIZE; i++) {
        string inputStr = sampleStr[i];
        cout << inputStr << endl;
        Solution s;
        int longestSubStringLen = s.lengthOfLongestSubstring(inputStr);
        cout << longestSubStringLen << endl;
    }

    return 0;
}

