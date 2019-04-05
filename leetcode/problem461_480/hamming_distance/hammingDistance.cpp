#include<iostream>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int xy = x ^ y;
        if (xy == 0)
            return 0;

        int i = 0, dist = 0;
        while (i <= 30) {
            if (xy & 0x1)
                ++dist;
            ++i;
            xy >>= 1;
        }
        return dist;
    }
};

int main()
{
#if 0
    int a = 1, b = 4;
    int a = 1, b = 3;
#endif
    int a = 1, b = 4;

    Solution s;
    int hDist = s.hammingDistance(a, b);
    cout << "Hamming distance between " << a << " and " << b << " is " << hDist << endl;
    return 0;
}
