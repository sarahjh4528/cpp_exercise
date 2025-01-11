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
1 <= nums.length <= 5 * 10^5
-2^31 <= nums[i] <= 2^31 - 1
*/
    bool increasingTriplet(vector<int>& nums) {
    }
};

int main()
{
    vector<vector<int>> vnums = {
        {1,2,3,4,5},
        {5,4,3,2,1},
        {2,1,5,0,4,6}
    };
    Solution s;

    for (auto nums : vnums) {
        s.printVec(nums);
        bool output = s.increasingTriplet(nums);
        cout << "Exists triple indices of increasing nums: " << output << endl;
    }

    return 0;
}
