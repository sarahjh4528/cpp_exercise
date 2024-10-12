#include<iostream>
#include<climits>

using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n) {
        if (n < 1)
            return false;

        int p2 = 0x1;
        for (int i = 0; i < 31; ++i) {
            if (n == p2)
                return true;
            p2 <<= 1;
        }
        return false;
    }
};

int main()
{
#if 0
    int n = 1;
    int n = 16;
    int n = 218;
    int n = 512;
    int n = INT_MAX;
    int n = 1073741824;
    int n = 0;
#endif
    int n = 512;

    Solution s;
    bool isPow = s.isPowerOfTwo(n);
    cout << n << " is power of 2 : " << isPow << endl;
    return 0;
}
