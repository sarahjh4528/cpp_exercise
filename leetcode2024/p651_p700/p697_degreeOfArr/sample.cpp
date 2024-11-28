/*
1 <= nums.length() <= 50,000
0 <= nums[i] <= 49,999
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

    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, pair<int, int>> nfreq;
        int maxfreq = 0, res = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int cur = nums[i];
            if (nfreq.count(cur))
                nfreq[cur].first++;
            else
                nfreq[cur] = {1, i};
            if (nfreq[cur].first > maxfreq) {
                maxfreq = nfreq[cur].first;
                res = i - nfreq[cur].second + 1;
            } else if (nfreq[cur].first == maxfreq) {
                res = min(res, i-nfreq[cur].second + 1);
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> vnums = {
        {1,2,2,3,1},
        {1,2,2,3,1,4,2}
    };
    Solution s;

    for (auto nums : vnums) {
        s.printVec(nums);
        int output = s.findShortestSubArray(nums);
        cout << "Max freq of element with shortest length: " << output << endl;
    }
    return 0;
}
