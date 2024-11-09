/*
Constraints:

-109 <= lower <= upper <= 109
0 <= nums.length <= 100
lower <= nums[i] <= upper
All the values of nums are unique.
*/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << ", ";
    }

/*
Runtime 0 ms Beats 100.00%
Memory 8.54 MB Beats 47.11%
*/
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<vector<int>> res;
        // lower <= nums[0] due to 3rd constraint, otherwise need to forward nums to num >= lower
        for (int i = 0; i < nums.size() && nums[i] <= upper; i++) {
            if (nums[i] > lower)
                res.push_back({lower, nums[i]-1});
            lower = nums[i] + 1;
        }
        if (lower <= upper)
            res.push_back({lower, upper});
        return res;
    }
};

int main()
{
    vector<vector<int>> vnums = {
        {0,1,3,50,75},
        {-1}
    };
    Solution s;

    vector<int> vlowers = {0, -1};
    vector<int> vuppers = {99, -1};

    for (int i = 0; i < vlowers.size(); i++) {
        s.printVec(vnums[i]);
        cout << vlowers[i] << " - " << vuppers[i] << endl;
        vector<vector<int>> output = s.findMissingRanges(vnums[i], vlowers[i], vuppers[i]);
        for (auto row : output)
            s.printVec(row);
        cout << endl;
    }
    return 0;
}
