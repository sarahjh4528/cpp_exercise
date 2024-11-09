/*
Constraints:

-109 <= lower <= upper <= 109
0 <= nums.length <= 100
lower <= nums[i] <= upper
All the values of nums are unique.
*/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << ", ";
    }

    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
    }
};

int main()
{
    vector<vector<int>> vnums = {
        {0,1,3,50,75},
        {-1}
    };
    Solution s;

    vector<int> vlowers = {0, -1};
    vector<int> vuppers = {99, -1};

    for (int i = 0; i < vlowers.size(); i++) {
        s.printVec(vnums[i]);
        cout << vlowers[i] << " - " << vuppers[i] << endl;
        vector<vector<int>> output = s.findMissingRanges(vnums[i], vlowers[i], vuppers[i]);
        for (auto row : output)
            s.printVec(row);
        cout << endl;
    }
    return 0;
}
