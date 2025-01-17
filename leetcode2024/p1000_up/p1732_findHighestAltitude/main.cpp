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
n == gain.length
1 <= n <= 100
-100 <= gain[i] <= 100
*/
/*
Runtime 0 ms Beats 100.00%
Memory 10.85 MB Beats 37.96%
*/
    int largestAltitude(vector<int>& gain) {
        int res = 0, netgain = 0;
        for (auto ng : gain) {
            netgain += ng;
            res = max(res, netgain);
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> vgain = {
        {-5,1,5,0,-7},
        {-4,-3,-2,-1,4,3,2}
    };
    Solution s;

    for (auto gain : vgain) {
        s.printVec(gain);
        int output = s.largestAltitude(gain);
        cout << "Giving above net gains, higest altitude: " << output << endl;
    }

    return 0;
}
