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

    vector<int> productExceptSelf(vector<int>& nums) {
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
