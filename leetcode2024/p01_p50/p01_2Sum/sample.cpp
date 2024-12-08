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
Constraints:

2 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
*/
    vector<int> twoSum(vector<int>& nums, int target) {
    }
};

int main()
{
    vector<vector<int>> vnums = {
        {2,7,11,15},
        {3,2,4},
        {3,3}
    };
    vector<int> vtarget = {9, 6, 6};
    Solution s;

    for (int i = 0; i < vtarget.size(); i++) {
        s.printVec(vnums[i]);
        vector<int> output = s.twoSum(vnums[i], vtarget[i]);
        cout << "Index of numbers to get target " << vtarget[i] << endl;
        s.printVec(output);
    }
    return 0;
}
