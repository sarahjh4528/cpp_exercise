#include<iostream>

using namespace std;

class Solution
{
public:
    double getPow(double x, int n) {
        if (n == 1)
            return x;
        else if (n == -1)
            return 1/x;

        double temp = getPow(x, n>>1);
        return (n & 0x1)? temp*temp*x : temp*temp;
        
    }

    double myPow(double x, int n) {
        if (x == 0 && n > 0) return 0;
        if (x == 1 || n == 1) return x;
        if (x == -1) return (n & 0x1)? x : -x;
        if (n == -1) return 1/x;
        if (n == 0) return 1;

        return getPow(x, n);
    }
};

int main()
{
#if 0
    double x = 2;
    int n = 10;

    double x = 2.1;
    int n = 3;

    double x = 2.0;
    int n = -2;

    double x = 0.44528;
    int n = 0;

    double x = 34.00515;
    int n = -3;
#endif
    double x = -1;
    int n = -2147483648;

    Solution s;
    double xPowN = s.myPow(x, n);
    cout << xPowN << endl;
    return 0;
}
