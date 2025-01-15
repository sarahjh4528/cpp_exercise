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
1 <= nums[i] <= 10^9
1 <= k <= 10^9
*/
    int maxOperations(vector<int>& nums, int k) {
    }
};

int main()
{
    vector<vector<int>> vnums = {
        {1,2,3,4},
        {3,1,3,4,3}
    };
    vector<int> vk = {5,6};
    Solution s;

    for (int i = 0; i < vk.size(); i++) {
        s.printVec(vnums[i]);
        int output = s.maxOperations(vnums[i], vk[i]);
        cout << "Max num of " << vk[i] << "-sum pairs: " << output << endl;
    }

    return 0;
}
