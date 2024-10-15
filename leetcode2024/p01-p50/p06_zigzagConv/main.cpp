/*
Runtime 3 ms Beats 98.14%
Memory 13.59 MB Beats 60.42%
*/
class Solution {
public:
    string convert(string s, int numRows) {
        int slen = s.length();
        if (slen < 3 || numRows < 2)
            return s;
        vector<string> vs(numRows, "");
        int div = (numRows<<1) - 2;
        for (int i = 0; i < slen; i++) {
            int rem = i % div;
            if (rem < numRows)
                vs[rem] += s[i];
            else
                vs[(numRows<<1)-rem-2] += s[i];
        }
        string ret = "";
        for (auto str : vs)
            ret += str;
        return ret;
    }
};
