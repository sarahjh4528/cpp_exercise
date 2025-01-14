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
1 <= nums.length <= 10^4
-2^31 <= nums[i] <= 2^31 - 1
*/
    void moveZeroes(vector<int>& nums) {
    }

};

int main()
{
    vector<vector<int>> vnums = {
        {0,1,0,3,12},
        {0}
    };
    Solution s;

    for (auto nums : vnums) {
        s.printVec(nums);
        s.moveZeroes(nums);
        cout << "After move zeros. " << endl;
        s.printVec(nums);
    }

    return 0;
}
