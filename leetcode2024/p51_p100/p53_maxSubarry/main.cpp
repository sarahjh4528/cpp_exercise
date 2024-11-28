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

/*
Runtime 0 ms Beats 100.00%
Memory 71.62 MB Beats 5.57%
Time: O(n), Space: O(1)
*/
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, curSum = 0;
        for (auto n : nums) {
            curSum += n;
            maxSum = max(curSum, maxSum);
            if (curSum < 0)
                curSum = 0;
        }
        return maxSum;
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
