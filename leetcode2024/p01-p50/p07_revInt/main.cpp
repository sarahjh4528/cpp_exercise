/*
Runtime 0 ms Beats 100.00%
Memory 8.13 MB Beats 93.21%
*/
class Solution {
public:
    int reverse(int x) {
        int res = 0, high = INT_MAX/10, low = INT_MIN/10;
        while (x) {
            int tmp = x % 10;
            if (res > high || (res == high && tmp > 7))
                return 0;
            if (res < low || (res == low && tmp > 8))
                return 0;
            res = res*10 + tmp;
            x /= 10;
        }
        return res;
    }
};
