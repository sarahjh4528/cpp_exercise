/*
Constraints:

2 <= nums.length <= 10^5
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
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

/*
Runtime 0 ms Beats 100.00%
Memory 40.16 MB Beats 39.50%
*/
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int cur = 1;
        for (int i = 0; i < n; i++) {   // left->right, save prev prod at res[i],
            res[i] = cur;
            cur *= nums[i];
        }
        cur = 1;
        for (int i = n-1; i >= 0; i--) {
            res[i] = res[i] * cur;
            cur *= nums[i];
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> vnums = {
        {1,2,3,4},
        {-1,1,0,-3,3}
    };
    Solution s;

    for (auto nums : vnums) {
        s.printVec(nums);
        vector<int> output = s.productExceptSelf(nums);
        cout << "Prod except self: " << endl;
        s.printVec(output);
    }
    return 0;
}
