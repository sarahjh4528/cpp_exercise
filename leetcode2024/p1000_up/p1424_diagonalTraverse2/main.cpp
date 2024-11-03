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

    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            int row = i;
            for (int j = 0; j <= i; j++) {
                if (j < nums[row].size())
                    res.push_back(nums[row][j]);
                    row--;
            }
        }
        for (int j = 1; j < nums.size(); j++) {
            int col = j;
            for (int i = nums.size()-1; i >= j; i--) {
                if (col < nums[i].size())
                    res.push_back(nums[i][col]);
                col++;
            }
        }
        return res;
    }
};

int main()
{
#if 1
    vector<vector<int>> nums = {
        {1,2,3,4,5},
        {6,7},
        {8},
        {9,10,11},
        {12,13,14,15,16}
    };
#else
    vector<vector<int>> nums = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
#endif
    Solution s;

    vector<int> output = s.findDiagonalOrder(nums);
    s.printVec(output);
    return 0;
}
