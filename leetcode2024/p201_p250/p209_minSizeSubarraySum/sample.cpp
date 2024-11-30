/*
Constraints:

1 <= target <= 10^9
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^4
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

    int minSubArrayLen(int target, vector<int>& nums) {
    }
};

int main()
{
    vector<vector<int>> vnums = {
        {2,3,1,2,4,3},
        {1,4,4},
        {1,1,1,1,1,1,1,1}
    };
    vector<int> vtarget = {7, 4, 11};
    Solution s;

    for (int i = 0; i < vtarget.size(); i++) {
        s.printVec(vnums[i]);
        int output = s.minSubArrayLen(vtarget[i], vnums[i]);
        cout << "Min sub array length to get target " << vtarget[i] << " : " << output << endl;
        
    }
    vector<int> input = {1,2,3,4,5,6};
    return 0;
}
