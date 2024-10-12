#include<iostream>
#include<vector>

using namespace std;

#define LOOP 9

string sampleStr[] = {
"abcabcbb",
"bbbbb",
"pwwkew",
"",
" ",
"au",
"dvdf",
"cdd",
"abba"
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> table(256, -1);
        int maxLen = 0, rstart = -1;
        for (int i = 0; i < s.length(); i++) {
            if (table[s[i]] > rstart)
                rstart = table[s[i]];
            table[s[i]] = i;
            maxLen = max((i - rstart), maxLen);
        }
        return maxLen;
    }
};

int main()
{
    for (int i = 0; i < LOOP; i++) {
        string inputStr = sampleStr[i];
        Solution s;
        int longestSubStringLen = s.lengthOfLongestSubstring(inputStr);
        cout << inputStr << endl;
        cout << longestSubStringLen << endl;
    }

    return 0;
}
