#include<iostream>

using std::cout;
using std::endl;

class Solution {
public:
    int reverse(int x) {
        int max = 0x7FFFFFFF;
        int min = 0x80000000;
        cout << "max: " << max << ", min: " << min << endl;

        long long rev = 0;
        while (x) {
            int mod = x % 10;
            rev = rev * 10 + mod;
            x /= 10;
        }
        cout << rev << endl;
        if (rev > max || rev < min)
            return 0;
        else
            return rev;
    }
};

int main()
{
//    int i = 123;
//    int i = -123;
//    int i = 1534236469;
//    int i = 120;
    int i = -2147483412;

    Solution s;
    int o = s.reverse(i);
    cout << o << endl;

    return 0;
}
