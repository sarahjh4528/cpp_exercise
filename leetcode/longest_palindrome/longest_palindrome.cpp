#include<iostream>
#include<vector>
  
using namespace std;

class Solution {
public:
    string longest_pal(string s) {
        int longestLen = 0;
        int lStart = 0, lEnd = 0;
        int fIndex = 0, bIndex = 0;
        int curIndex = 0;
        int strLen = s.length();
        while (curIndex < strLen) {
            fIndex = curIndex; 
            bIndex = curIndex;
            while (fIndex + 1 < strLen && s[fIndex+1] == s[bIndex]) {
                // Same character. Keep move fIndex forward until hit different char or string end.
                ++fIndex;
                ++curIndex;
            }
            /* From curIndex, found max string with same char, within bIndex and fIndex, including border.
             * For instance, case abbbc, bIndex: 1, fIndex: 4. Same char string length: fIndex - bIndex
             * Expand backward and forward to find more palindrome char.
             */
            while (bIndex-1 >= 0 && fIndex+1 < strLen && s[fIndex+1] == s[bIndex-1]) {
                --bIndex;
                ++fIndex;
            }
            if ((fIndex - bIndex) > (lEnd - lStart)) {
                lEnd = fIndex;
                lStart = bIndex;
            }
            ++curIndex;
        }
        return s.substr(lStart, (lEnd - lStart+1));
    }
};

/*
Cases: a, ab, aba, aaab, abbb, abba, abbc, abaabc...
*/
int main() {
    vector<string> inStrs = {
       "a",
       "ab",
       "aba",
       "aaab",
       "abbb",
       "abba",
       "abbc",
       "abaabc",
       "babad"
    };
//    string inStr = "ababa";
    string inStr = "a";
    Solution s;

    for (auto inStr : inStrs) {
        string outStr = s.longest_pal(inStr);
        cout << "Input string: " << inStr << endl;
	    cout << "Palindrome: " << outStr << endl;
    }
    return 0;
}
