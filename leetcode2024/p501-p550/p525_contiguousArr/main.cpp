/*
Constraints:

1 <= nums.length <= 10^5
nums[i] is either 0 or 1.
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
Design: Prefix sum, treat 0:-1, 1:1, when sum == 0, found arr with equal 0 & 1
            0  1  2  3  4  5  6  7  8  9  10  11
            0  1  1  0  0  0  1  0  0  1  1   0
Prefix sum: -1 0  1  0  -1 -2 -1 -2 -3 -2 -1  -2
            [  ]  ==> i+1
              [         ] ==> i - map[sum] ==> 4 - 0 = 4

Following 2 possibilities indicates arr with same 0s and 1s
prefix sum == 0
prefix sum - previous same prefix sum == 0

Runtime 21 ms Beats 93.20%
Memory 88.37 MB Beats 68.18%
Time : O(n), Space : O(n)
*/
    int findMaxLength(vector<int>& nums) {
        int sum = 0, maxLen = 0;
        unordered_map<int, int> smap;   // sum position
        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] == 0)? -1 : 1;
            if (sum == 0)
                maxLen = max(maxLen, i+1);
            else if (smap.count(sum))
                maxLen = max(maxLen, i - smap[sum]);
            else
                smap[sum] = i;
        }
        return maxLen;
    }

};

int main()
{
    vector<vector<int>> vnums = {
        {0, 1},
        {0, 1, 0},
        {0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0},
        {1, 1, 1}
    };
    Solution s;

    for (auto nums : vnums) {
        s.printVec(nums);
        int output = s.findMaxLength(nums);
        cout << "Maximum length of contiguous subarry with same 0s and 1s: " << output << endl;
    }

    return 0;
}
