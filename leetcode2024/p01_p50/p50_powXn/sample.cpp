/*
Constraints:

-100.0 < x < 100.0
-2^31 <= n <= 2^31-1
n is an integer.
Either x is not zero or n > 0.
-10^4 <= x^n <= 10^4
*/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
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
