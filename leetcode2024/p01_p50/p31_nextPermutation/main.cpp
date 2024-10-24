/*
Runtime 0 ms Beats 100.00%
Memory 14.79 MB Beats 81.06%
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

    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return;

        int tp = n-2;
        while (tp >= 0 && nums[tp] > nums[tp+1])
            tp--;

        if (tp < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int sp = tp + 1;
        while (sp < n-1 && nums[sp+1] > nums[tp])
            sp++;
        swap(nums[sp], nums[tp]);
        reverse(nums.begin()+tp+1, nums.end());
    }
};

int main()
{
    vector<int> nums = {1,2,3};
    Solution s;

    for (int i = 0; i < 6; i++) {
        s.printVec(nums);
        s.nextPermutation(nums);
        cout << "Next permuation: " << endl;
        s.printVec(nums);
    }

    return 0;
}
