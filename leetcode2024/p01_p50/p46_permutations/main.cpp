/*
Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
    void solve(vector<int>& nums, int cur, vector<vector<int>>& res) {
        if (cur == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = cur; i < nums.size(); i++) {
            swap(nums[i], nums[cur]);
            solve(nums, cur+1, res);
            swap(nums[i], nums[cur]);
        }
    }
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        solve(nums, 0, res);
        return res;
    }
};

int main()
{
    vector<vector<int>> vnums = {
        {1,2,3},
        {0,1},
        {1}
    };
    Solution s;

    for (auto nums : vnums) {
        vector<vector<int>> output = s.permute(nums);
        for (auto p : output )
            s.printVec(p);
        
    }
    return 0;
}
