#include<iostream>
#include<climits>

using namespace std;

class Solution
{
public:
    unsigned divideGetQuotient(long long dividend, long long divisor, unsigned& quotient) {
        if (dividend < divisor)
            return quotient;

        long long product = divisor;
        unsigned qt = 1;
        while (dividend >= (product<<1)) {
            product <<= 1;
            qt <<= 1;
        }
        qt += quotient;
        return divideGetQuotient(dividend - product, divisor, qt);
    }

    int divide(int dividend, int divisor) {
        if (dividend == 0)
            return 0;
        if (divisor == 1)
            return dividend;
        if (divisor == -1)
            return (dividend == INT_MIN)? INT_MAX : -dividend;

        bool isNegative = false;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
            isNegative = true;

        unsigned quotient = 0;
        long long ldividend = abs((long long)dividend);
        long long ldivisor = abs((long long)divisor);

        return (isNegative)? -divideGetQuotient(ldividend, ldivisor, quotient)
                            : divideGetQuotient(ldividend, ldivisor, quotient);
    }
};
int main()
{
#if 0
    int dividend = 10, divisor = -3;
    int dividend = 7, divisor = -2;
    int dividend = 100, divisor = 3;
    int dividend = 0, divisor = -2;
    int dividend = -2147483648, divisor = -1;
    int dividend = 2147483647, divisor = -1;
    int dividend = 2147483647, divisor = 1;
    int dividend = -2147483648, divisor = 1;
    int dividend = -2147483648, divisor = 2;
#endif
    int dividend = 100, divisor = 3;
    Solution s;
    int quotient = s.divide(dividend, divisor);
    cout << dividend << " / " << divisor << " = " << quotient << endl;
    return 0;
}
