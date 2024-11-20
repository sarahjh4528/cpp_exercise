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

    int findTargetSumWays(vector<int>& nums, int target) {
    }
};

int main()
{
    vector<vector<int>> vnums = {
        {1,1,1,1,1},
        {1}
    };
    vector<int> vt = {3,1};
    Solution s;

    for (int i = 0; i < vt.size(); i++) {
        s.printVec(vnums[i]);
        int output = s.findTargetSumWays(vnums[i], vt[i]);
        cout << "Number of ways to form target " << vt[i] << " : " << output << endl;
    }
    return 0;
}
