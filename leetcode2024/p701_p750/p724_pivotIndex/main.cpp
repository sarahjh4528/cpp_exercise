/*
Runtime 7 ms Beats 98.98%
Memory 35.26 MB Beats 23.98%
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

    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> sums(n, 0);
        sums[0] = nums[0];
        for (int i = 1; i < n; i++)
            sums[i] = sums[i-1] + nums[i];
        if (sums[n-1] - sums[0] == 0)
            return 0;
        for (int i = 1; i < n; i++) {
            if (sums[n-1] - sums[i] == sums[i-1])
                return i;
        }
        return -1;
    }
};

int main()
{
    vector<vector<int>> input = {
        {1,7,3,6,5,6},
        {1,2,3},
        {2,1,-1}
    };
    Solution s;

    for (auto nums : input) {
        s.printVec(nums);
        int output = s.pivotIndex(nums);
        cout << "Pivot index: " << output << endl;
    }

    return 0;
}
