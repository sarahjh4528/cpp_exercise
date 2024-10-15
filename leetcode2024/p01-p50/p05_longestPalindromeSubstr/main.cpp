/*
Runtime 6 ms Beats 96.96%
Memory 8.24 MB Beats 97.16%
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int slen = s.length();
        if (slen < 2)
            return s;
        int start = 0, llen = 0, i = 0;
        while (i < slen) {
            if (slen - i <= (llen>>1))
                break;
            int left = i, right = i;
            while (right < slen-1 && s[right] == s[right+1]) // same char
                right++;
            i = right + 1;
            while (left > 0 && right < slen-1 && s[left-1] == s[right+1]) {
                left--;
                right++;
            }
            if (right-left+1 > llen) {
                start = left;
                llen = right - left + 1;
            }
        }
        return s.substr(start, llen);
    }
};
