#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
    double powHelper(double x, long long n) {
        if (n < 0) {
            x = (double)1 / x;
            n = -n;
        }

        double res = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                res *= x;
                n--;
            }
            x = x*x;
            n /= 2;
        }
        return res;
    } 
public:
    double myPow(double x, int n) {
        if (x == 1.0 || n == 0)
            return 1.0;
        if (n == 1)
            return x;
        return powHelper(x, (long long)n);
    }
};

int main()
{
    vector<double> input = { 2.00000, 2.10000, 2.00000 };
    vector<double> vn = { 10, 3, -2 };
    Solution s;

    for (int i = 0; i < vn.size(); i++) {
        double output = s.myPow(input[i], vn[i]);
        cout << input[i] << " to the power of " << vn[i] << ": " << output << endl;
    }
    return 0;
}
