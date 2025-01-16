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
0 <= k <= nums.length
*/
/*
Runtime 0 ms Beats 100.00%
Memory 59.06 MB Beats 84.11%

Time: O(N), Space: O(1)
*/
    int longestOnes(vector<int>& nums, int k) {
        int res = 0, low = 0, high;
        for (high = 0; high < nums.size(); high++) {
            if (nums[high] == 0)
                k--;
            if (k < 0) { // Got a window, slide same size window to right,
                         // until k >= 0, with right keeps moving, we're able to get bigger window.
                if (nums[low] == 0)
                    k++;
                low++;
            }
        }
        return high - low;
    }
};

int main()
{
    vector<vector<int>> input = {
        {1,1,1,0,0,0,1,1,1,1,0},
        {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1}
    };
    vector<int> vk = {2, 3};
    Solution s;

    for (int i = 0; i < vk.size(); i++) {
        s.printVec(input[i]);
        int output = s.longestOnes(input[i], vk[i]);
        cout << "Max consecutive ones: " << output << endl;
    }
    return 0;
}
