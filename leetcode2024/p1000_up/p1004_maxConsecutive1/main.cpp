/*
Runtime 3 ms Beats 93.48%
Memory 58.26 MB Beats 16.18%
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

    int longestOnes(vector<int>& nums, int k) {
        int res = 0, zeros = 0, low = 0, high = 0;
        while (high < nums.size()) {
            if (nums[high] == 0)
                zeros++;
            if (zeros <= k)
                res = max(res, high-low+1);
            else {
                if (nums[low] == 0)
                    zeros--;
                low++;
            }
            high++;
        }
        return res;
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
