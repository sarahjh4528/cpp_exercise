/*
Runtime 4 ms Beats 100.00%
Memory 21.10 MB Beats 97.71%
*/

class Solution {
    bool isValidPalindrome(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int start = 0, end = s.length()-1;
        while (start < end) {
            if (s[start] == s[end]) {
                start++;
                end--;
            } else {
                return isValidPalindrome(s, start+1, end) || isValidPalindrome(s, start, end-1);
            }
        }
        return true;
    }
};
