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
Runtime 7 ms Beats 93.29%
Memory 28.68 MB Beats 91.60%
*/
    int findShortestSubArray(vector<int>& nums) {
        int res = 0, maxfreq = 0;
        unordered_map<int, pair<int, int>> nmap;    // num : [freq, i]
        for (int i = 0; i < nums.size(); i++) {
            int cur = nums[i];
            if (nmap.count(cur))
                nmap[cur].first++;
            else
                nmap[cur] = {1, i};
            if (nmap[cur].first > maxfreq) {
                res = i - nmap[cur].second + 1;
                maxfreq = nmap[cur].first;
            } else if (nmap[cur].first == maxfreq) {
                res = min(res, i - nmap[cur].second + 1);
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
