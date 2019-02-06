#include<iostream>
#include<climits>

using std::cout;
using std::endl;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x;

        int high = x, low = 0, mid = 0;
        while (low < high) {
            unsigned long long mid = ((high - low) >> 1) + low;
            // It's good to save mid * mid
            unsigned long long p = mid * mid;
            if (p < x && low != mid) {
                low = mid;
            } else if (p > x) {
                high = mid;
            } else {
                return mid;
            }
        }
        return mid;
    }
};

int main() {
#if 0
    int target = 4;
    int target = 8;
    int target = 256;
    int target = 0;
    int target = 2;
    int target = 1000;
    int target = 2147395599;
#endif
    int target = 2147395599;

    Solution s;
    int sqrtRet = s.mySqrt(target);

    cout << "target: " << target << ", sqrt: " << sqrtRet << endl;
    return 0;
}
