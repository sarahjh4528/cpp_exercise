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
1 <= nums.length <= 10^4
-1000 <= nums[i] <= 1000
*/
    int pivotIndex(vector<int>& nums) {
    }
};

int main()
{
    vector<vector<int>> input = {
        {1,7,3,6,5,6},
        {1,2,3},
        {2,1,-1}
    };
    Solution s;

    for (auto nums : input) {
        s.printVec(nums);
        int output = s.pivotIndex(nums);
        cout << "Pivot index: " << output << endl;
    }

    return 0;
}
