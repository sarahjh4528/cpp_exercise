/*
Runtime 34 ms Beats 99.81%
Memory 45.46 MB Beats 45.11%
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

    unordered_map<int, int> preSum;
        preSum[0] = 1;
        int sum = 0, res = 0;
        for (auto n : nums) {
            sum += n;
            if (preSum.count(sum-k))
                res += preSum[sum-k];
            preSum[sum]++;
        }
        return res;

};

int main()
{
    Solution s;

    vector<int> input = {1,2,3,4,5,6};
    s.printVec(input);
    return 0;
}
