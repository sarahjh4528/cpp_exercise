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
/*
Runtime 0 ms Beats 100.00%
Memory 23.85 MB Beats 41.96%
Time: O(n), Space : O(1)
*/
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        while (j < nums.size()) {
            if (nums[j] != 0)
                nums[i++] = nums[j];
            j++;
        }
        fill(nums.begin()+i, nums.end(), 0);
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
