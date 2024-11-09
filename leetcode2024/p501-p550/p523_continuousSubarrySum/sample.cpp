/*
Constraints:

1 <= nums.length <= 10^5
0 <= nums[i] <= 10^9
0 <= sum(nums[i]) <= 2^31 - 1
1 <= k <= 2^31 - 1
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

/*
Design : prefix sum & hash table

Range of sum before a-b, Prefix(b) - Prefix(a)
To get sum divisible by 5 => rangeSum % 5 = 0
RangeSum % 5 = 0 => (prefix(b) - prefix(a)) % 5 = 0 => prefix(a)%5 - prefix(b)%5 = 0

Therefore we're looking for prefix(b)%5 = prefix(a)%5
*/
    bool checkSubarraySum(vector<int>& nums, int k) {
    }
};

int main()
{
    vector<vector<int>> input = {
        {23,2,4,6,7},
        {23,2,6,4,7},
        {23,2,6,4,7},
        {5,0,0,0}           // Do up update modMap[curMod]index, move index range check inside if
    };
    vector<int> vk = {6,6,13,3};
    Solution s;

    for (int i = 0; i < input.size(); i++) {
        s.printVec(input[i]);
        bool output = s.checkSubarraySum(input[i], vk[i]);
        cout << "Exit contigous array sum to multiple of " << vk[i] << " : " << output << endl;
    }

    return 0;
}
