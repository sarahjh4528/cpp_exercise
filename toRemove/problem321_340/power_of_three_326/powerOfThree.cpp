#include<iostream>
#include<cmath>

using namespace std;

class Solution
{
public:
    bool isPowerOfThree(int n) {
        if (n)
            return (log10(n)/log10(3) == int(log10(n)/log10(3)));
        else
            return false;
    }
};

int main()
{
    int n[4] = {27, 0, 9, 45};
    Solution s;
    for (auto i : n) {
        bool isP3 = s.isPowerOfThree(i);
        if (isP3)
            cout << i << " is power of three" << endl;
        else
            cout << i << " is not power of three." << endl;
    }
    return 0;
}
