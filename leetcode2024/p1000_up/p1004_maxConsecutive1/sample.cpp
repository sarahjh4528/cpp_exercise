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
    int longestOnes(vector<int>& nums, int k) {
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
