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
n == nums.length
1 <= k <= n <= 10^5
-10^4 <= nums[i] <= 10^4
*/
    double findMaxAverage(vector<int>& nums, int k) {
    }
};

int main()
{
    vector<vector<int>> vnums = {
        {1,12,-5,-6,50,3},
        {5}
    };
    vector<int> vk = {4,1};
    Solution s;

    for (int i = 0; i < vk.size(); i++) {
        s.printVec(vnums[i]);
        double output = s.findMaxAverage(vnums[i], vk[i]);
        cout << "Max Avg of subarray: " << output << endl;
    }

    return 0;
}
