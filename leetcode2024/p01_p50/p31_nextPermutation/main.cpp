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
        int tp = n - 2;
        while (tp >= 0 && nums[tp] >= nums[tp+1])
            tp--;
        if (tp >= 0) {
            int sp = n - 1;
            while (sp > tp && nums[sp] <= nums[tp])
                sp--;
            swap(nums[tp], nums[sp]);
        }
        
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
