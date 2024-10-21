/*
Runtime 7 ms Beats 81.92%
Memory 12.56 MB Beats 49.26%
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if (len == 0)
            return 0;
        int start = 0, mlen = 0;
        vector<int> pos(512, -1);
        for (int i = 0; i < len; i++) {
            if (pos[s[i]] != -1 && start <= pos[s[i]]) {
                mlen = max(mlen, i - start);
                start = pos[s[i]] + 1;
            }
            pos[s[i]] = i;
        }
        mlen = max(mlen, len - start);
        return mlen;
    }
};
