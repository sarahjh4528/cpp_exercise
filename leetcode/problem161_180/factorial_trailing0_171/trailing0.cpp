#include<iostream>
#include<climits>
#include<stdexcept>

using namespace std;

class Solution
{
public:
    int trailingZeroes(int n) {
        if (n < 5)
            return 0;
        int ret = 0;
        while (n) {
            ret += n / 5;
            n /= 5;
        }
        
        return ret;
    }
};

int main()
{
#if 0
    int n = 3;
    int n = 5;
    int n = 100;
    int n = 10;
    int n = 25;
#endif
    int n = 25;

    Solution s;
    int trail0s = s.trailingZeroes(n);
    cout << n << "!" << ", trailing 0 num: " << trail0s << endl;

    return 0;
}

