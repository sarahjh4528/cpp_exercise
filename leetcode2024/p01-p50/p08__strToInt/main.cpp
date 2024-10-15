/*
Runtime 3 ms Beats 59.41%
Memory 8.18 MB Beats 100.00%
*/
class Solution {
public:
    int myAtoi(string s) {
        int len = s.length();
        if (len == 0)
            return 0;
        int ret = 0, i = 0;
        bool isNegative = false;
        while (i < len && s[i] == ' ')
            i++;
        if (i < len && (s[i] == '-' || s[i] == '+')) {
            isNegative = (s[i] == '-')? true : false;
            i++;
        }
        while (i < len && (s[i] <= '9' && s[i] >= '0')) {
            int n = s[i] - '0';
            if (ret > INT_MAX/10 || (ret == INT_MAX/10 && n > 7))
                return (isNegative)? INT_MIN : INT_MAX;
            ret = ret * 10 + n;
            i++;
        }
        return (isNegative)? -ret : ret;
    }
};
