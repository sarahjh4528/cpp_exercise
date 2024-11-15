/*
Constraints:

1 <= nums.length <= 2 * 10^4
-2^31 <= nums[i] <= 2^31 - 1
target is an integer from nums.
At most 10^4 calls will be made to pick.
*/
#include<bits/stdc++.h>
#include<iostream>
#include<random>

using namespace std;

class Solution {
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    Solution(vector<int>& nums) {
    }
    
    int pick(int target) {
    }

};

int main()
{
    vector<int> nums = {1, 2, 3, 3, 3};
    vector<int> vt = {3,1,3};
    Solution s(nums);
    s.printVec(nums);

    for (auto t : vt) {
        int output = s.pick(t);
        cout << "Index of " << t << " : " << output << endl;
    }

    return 0;
}
