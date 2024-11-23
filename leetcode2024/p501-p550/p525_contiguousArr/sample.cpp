/*
Constraints:

1 <= nums.length <= 10^5
nums[i] is either 0 or 1.
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

    int findMaxLength(vector<int>& nums) {
    }

};

int main()
{
    vector<vector<int>> vnums = {
        {0, 1},
        {0, 1, 0},
        {0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0},
        {1, 1, 1}
    };
    Solution s;

    for (auto nums : vnums) {
        s.printVec(nums);
        int output = s.findMaxLength(nums);
        cout << "Maximum length of contiguous subarry with same 0s and 1s: " << output << endl;
    }

    return 0;
}
