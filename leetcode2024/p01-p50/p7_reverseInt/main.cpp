/*
Runtime 0 ms Beats 100.00%
Memory 8.13 MB Beats 93.22%
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

    int reverse(int x) {
        int res = 0, high = INT_MAX/10, low = INT_MIN/10;
        while (x) {
            int tmp = x % 10;
            if (res > high || (res == high && tmp > 7))
                return 0;
            if (res < low || (res == low && tmp < 8))
                return 0;
            res = res*10 + tmp;
            x /= 10;
        }
        return res;
    }
};

int main()
{
    vector<int> input = {123, -123, 120, INT_MAX, INT_MIN};
    Solution s;

    for (auto x : input) {
        int output = s.reverse(x);
        cout << "Reverse " << x << " : " << output << endl;
    }
    return 0;
}
