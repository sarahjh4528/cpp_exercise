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

// 4 ms solution
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool oneDistHelper(string s, string l) {
        // s length <= l length

        int i = 0;
        int sLen = s.length(), lLen = l.length();
        while (i < sLen && s[i] == l[i])
            ++i;

        // Found an unmatch
        if (sLen == lLen)
            ++i;    // skip the diff

        while (i < sLen) {
            if (sLen < lLen && s[i] != l[i+1])
                return false;
            if (sLen == lLen && s[i] != l[i])
                return false;
            ++i;
        }
        return true;
    }

    bool isOneEditDistance(string s, string t) {
        if ((s.empty() && t.empty()) || s == t)
            return false;

        if (s.length() > t.length())
            return (s.length() - t.length() >= 2)? false : oneDistHelper(t, s);
        else if (s.length() < t.length())
            return (t.length() - s.length() >= 2)? false : oneDistHelper(s, t);
        else
            return oneDistHelper(s, t);
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
