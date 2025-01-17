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
1 <= nums.length <= 10^5
nums[i] is either 0 or 1.
*/
/*
Runtime 1 ms Beats 36.47%
Memory 60.08 MB Beats 50.46%

Time: O(n), Space: O(1)
*/
    int longestSubarray(vector<int>& nums) {
        int res = 0, left = 0, right = 0, cnt = 1;
        for (right = 0; right < nums.size(); right++) {
            if (nums[right] == 0)
                cnt--;
            if (cnt >= 0)
                res = max(res, right - left);
            else {
                if (nums[left] == 0)
                    cnt++;
                left++;
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> vnums = {
        {1,1,0,1},
        {0,1,1,1,0,1,1,0,1},
        {1,1,1}
    };
    Solution s;

    for (auto nums : vnums) {
        s.printVec(nums);
        int output = s.longestSubarray(nums);
        cout << "Num of longest subarry 1 after rm one element: " << output << endl;
    }
    return 0;
}
