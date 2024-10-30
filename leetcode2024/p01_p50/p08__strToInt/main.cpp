/*
Runtime 0 ms Beats 100.00%
Memory 9.14 MB Beats 27.63%
*/
class Solution {
public:
    int myAtoi(string s) {
        int res = 0, i = 0;
        int limit = INT_MAX / 10;
        bool isNegative = false;
        while (i < s.length() && s[i] == ' ')
            i++;
        if (i < s.length() && (s[i] == '-' || s[i] == '+')) {
            isNegative = (s[i] == '-')? true : false;
            i++;
        }
        while (i < s.length() && isdigit(s[i])) {
            if (res > limit || (res == limit && s[i] > '7'))
                return (isNegative)? INT_MIN : INT_MAX;
            res = res * 10 + (s[i] - '0');
            i++;
        }
        return (isNegative)? -res : res;
    }
};

int main() {
}
