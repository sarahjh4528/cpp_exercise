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

/*
-2^31 <= x <= 2^31 - 1
*/
/*
Runtime 0 ms Beats 100.00%
Memory 8.13 MB Beats 99.98%
*/
    int reverse(int x) {
        int res = 0, upper = INT_MAX/10, lower = INT_MIN/10;
        bool isNegative = false;
        while (x) {
            if (res > upper || (res == upper && x > 7))
                return 0;
            if (res < lower || (res == lower && x < -8))
                return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};

int main()
{
    vector<int> vx = {123, -123, 120};
    Solution s;

    for (auto x : vx) {
        int output = s.reverse(x);
        cout << "Reverse " << x << ": " << output << endl;
    }
    return 0;
}
