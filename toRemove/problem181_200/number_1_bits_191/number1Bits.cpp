#include<iostream>

using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            if (n & 0x1)
                ++count;
            n >>= 1;
        }
        return count;
    }
};
int main()
{
#if 0
    uint32_t n = 0b00000000000000000000000000001011;
    uint32_t n = 0b00000000000000000000000010000000;
    uint32_t n = 0b11111111111111111111111111111101;
#endif
    uint32_t n = 0b11111111111111111111111111111101;
    Solution s;
    int cnt = s.hammingWeight(n);
    cout << cnt << endl;
    return 0;
}
