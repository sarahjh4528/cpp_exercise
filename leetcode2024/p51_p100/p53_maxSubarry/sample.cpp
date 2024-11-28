/*
Constraints:

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
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

    int maxSubArray(vector<int>& nums) {
    }

};

int main()
{
    vector<vector<int>> vnums = {
        {-2,1,-3,4,-1,2,1,-5,4},
        {1},
        {5,4,-1,7,8}
    };
    Solution s;
    for (auto nums : vnums) {
        s.printVec(nums);
        int output = s.maxSubArray(nums);
        cout << "Largest sum of subarry has length: " << output << endl;
    }

    return 0;
}
