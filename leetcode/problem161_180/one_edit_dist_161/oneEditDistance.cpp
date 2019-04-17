/*
 * Given two strings s and t, determine if they are both one edit distance apart.
 * Note: 
 * There are 3 possiblities to satisify one edit distance apart:
 * Insert a character into s to get t
 * Delete a character from s to get t
 * Replace a character of s to get t
 *
 * Example 1:
 * Input: s = "ab", t = "acb"
 * Output: true
 * Explanation: We can insert 'c' into s to get t.
 *
 * Example 2:
 * Input: s = "cab", t = "ad"
 * Output: false
 * Explanation: We cannot get t from s by only one step.
 * 
 * Example 3:
 * Input: s = "1203", t = "1213"
 * Output: true
 * Explanation: We can replace '0' with '1' to get t.
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if ((s.empty() && t.empty()) || s == t)
            return false;

        int i = 0, j = 0;
        bool isOneDiff = false;
        int sLen = s.size(), tLen = t.size();
        while (i < sLen && j < tLen) {
            if (s[i] != t[j]) {
                if (isOneDiff)
                    return false;
                isOneDiff = true;
                if (sLen > tLen && i + 1 < sLen && s[i+1] == t[j]) {
                    ++i;
                    continue;
                } else if (sLen < tLen && j + 1 < tLen && s[i] == t[j+1]) {
                    ++j;
                    continue;
                }
            }
            ++i;
            ++j;
        }
        if ((isOneDiff && (i != sLen || j != tLen) ||
            i + 1 < sLen ||
            j + 1 < tLen))
            return false;

        return true;
    }
};

int main() {
    vector<string> sStr = {"ab", "cab", "1203", "1233"};
    vector<string> tStr = {"acb", "ad", "1213", "1213"};

    Solution s;
    for (int i = 0; i < sStr.size(); ++i) {
        bool isOneDist = s.isOneEditDistance(sStr[i], tStr[i]);
        cout << sStr[i] << " AND " << tStr[i] << " is one edit distance: " << isOneDist << endl;
    }
    return 0;
}
