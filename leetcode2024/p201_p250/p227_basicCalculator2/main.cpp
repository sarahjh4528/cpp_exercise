/*
Runtime 2 ms Beats 99.98%
Memory 10.96 MB Beats 96.26%
*/

class Solution {
public:
    int calculate(string s) {
        int i = 0, maxi = s.length()-1;
        int res = 0, n1 = 0, n2 = 0;
        char op = '+';
        while (i <= maxi) {
            while (s[i] == ' ' && i < maxi)
                i++;
            if (isdigit(s[i]))
                n2 = n2*10 + (s[i]-'0');
            if (!isdigit(s[i]) || i == maxi) {
                if (op == '+' || op == '-') {
                    res += n1;
                    n2 = (op == '-')? -n2 : n2;
                } else if (op == '*')
                    n2 = n1 * n2;
                else
                    n2 = n1 / n2;
                op = s[i];
                n1 = n2;
                n2 = 0;
            }
            i++;
        }
        res += n1;
        return res;
    }
};
