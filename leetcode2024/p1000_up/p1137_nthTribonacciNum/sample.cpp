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
0 <= n <= 37
The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.
*/
    int tribonacci(int n) {
    }
};

int main()
{
    vector<int> vn = {4,25};
    Solution s;

    for (auto n : vn) {
        int output = s.tribonacci(n);
        cout << n << "th tribonacci num: " << output << endl;
    }
    return 0;
}
