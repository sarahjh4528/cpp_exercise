/*
Runtime 84 ms Beats 41.85%
Memory 146.16 MB Beats 85.84%
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
        int sum = 0;
        unordered_map<int, int> modMap;  // prefixSum % 5, index
        modMap[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int curMod = sum % k;
            if (modMap.count(curMod)) {
                if (i - modMap[curMod] >= 2)
                    return true;
            } else {
                modMap[curMod] = i;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> input = 
        {23,2,4,6,7},
        {23,2,4,6,7},
        {23,2,4,6,7},
        {23,2,4,6,6},       // Need to init modMap[0]
        {5,0,0,0}           // Do up update modMap[curMod]index, move index range check inside if
    };
    vector<int> vk = {6,6,13,7,3};
    Solution s;

    s.printVec(input);
    return 0;
}
