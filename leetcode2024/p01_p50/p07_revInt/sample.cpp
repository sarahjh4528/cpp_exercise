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
    int reverse(int x) {
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
