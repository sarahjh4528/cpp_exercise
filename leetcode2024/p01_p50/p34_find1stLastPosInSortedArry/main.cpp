/*
Runtime 0 ms Beats 100.00%
Memory 16.45 MB Beats 7.05%
*/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
    int binarySearchBound(vector<int>& nums, int target, bool searchLow) {
        int low = 0, high = nums.size() - 1, res = -1;
        while (low <= high) {
            int mid = (high + low) / 2;
            if (nums[mid] < target)
                low = mid + 1;
            else if (nums[mid] > target)
                high = mid - 1;
            else {
                res = mid;  // Found target, continue search low or high bound
                if (searchLow)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }
        return res;
    }
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return {-1, -1};

        int low = binarySearchBound(nums, target, true);    // true: search low

        if (low == -1)
            return {-1, -1};

        int high = binarySearchBound(nums, target, false);  // false : search high
        return {low, high};
    }

};

int main()
{
    vector<vector<int>> vnums = {
        {5,7,7,8,8,10},
        {5,7,7,8,8,10},
        {}
    };
    vector<int> vtarget = {8,6,0};
    Solution s;

    for (int i = 0; i < vtarget.size(); i++) {
        s.printVec(vnums[i]);
        vector<int> output = s.searchRange(vnums[i], vtarget[i]);
        cout << "Position of " << vtarget[i] << " in arr : " << endl;
        s.printVec(output);
    }
    return 0;
}
