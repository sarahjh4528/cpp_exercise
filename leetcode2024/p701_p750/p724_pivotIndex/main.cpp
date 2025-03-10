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
/*
Runtime 1 ms Beats 30.25%
Memory 36.33 MB Beats 19.06%

Time: O(n), loop forward once, backward once, O(2n) => O(n)
Space : O(n)
*/
    int pivotIndex(vector<int>& nums) {
        int size = nums.size(), sum = 0;
        vector<int> sums(size, 0);
        for (int i = 0; i < size; i++) {
            sums[i] = sum;
            sum += nums[i];
        }
        sum = 0;
        int res = size;
        for (int i = size-1; i >= 0; i--) {
            if (sums[i] == sum)
                res = min(res, i);
            sum += nums[i];
        }
        return (res == size)? -1 : res;
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
