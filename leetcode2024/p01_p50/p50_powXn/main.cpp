/*
Runtime 0 ms Beats 100.00%
Memory 8.36 MB Beats 40.89%
*/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    double helper(double x, long long n) {
        if (n == 0 || x == 1.0)
            return 1;
        if (n == 1)
            return x;
        if (n < 0) {
            x = 1.0 / x;
            n = -n;
        }
        double res = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                res = res * x;
                n--;
            }
            x *= x;
            n /= 2;
        }
        return res;
    }

    double myPow(double x, int n) {
        return helper(x, (long long)n);
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
