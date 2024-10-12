#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    bool isUgly(int num) {
        if (num <= 0)
            return false;
        if (num == 1)
            return true;
        const int ugFactor[3] = {2, 3, 5};
        for (auto u : ugFactor) {
            while (num % u == 0) {
                num /= u;
            }
            if (num == 1)
                return true;
        }
        return false;
    }
};

int main()
{
#if 0
    int num = 50;
    int num = 38;
    int num = 0;
    int num = 2;
    int num = 27;
    int num = -27;
#endif
    int num = 27;

    Solution s;
    bool isUg = s.isUgly(num);
    cout << num << " is ugly: " << isUg << endl;
    return 0;
}
