/*
Runtime 11 ms Beats 81.99%
Memory 19.64 MB Beats 26.83%
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

    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++)
            res ^= nums[i];
        return res;
    }
};

int main()
{
    Solution s;

    vector<int> input = {1,2,3,4,5,6};
    s.printVec(input);
    return 0;
}
