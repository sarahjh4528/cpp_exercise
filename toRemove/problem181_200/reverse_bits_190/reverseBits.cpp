#include<iostream>

using namespace std;

class Solution
{
public:
    // abcdefgh -> hgfedcab -> then reverse the internal 4 bits of each a,b,c,d...
    uint32_t reverseBits(uint32_t n) {
        n = n >> 16 | n << 16;                              // efghabcd
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);  // ghefcdab
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);  // hgfedcba
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);  // Reverse 2 bits in side each 4 bits
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);  // Reverse each pair of 2 bits
        return n;
    }
};
int main()
{
#if 0
    uint32_t n = 43261596;
    uint32_t n = 4294967293;
#endif
    uint32_t n = 4294967293;

    Solution s;
    uint32_t o = s.reverseBits(n);
    cout << o << endl;
    return 0;
}
