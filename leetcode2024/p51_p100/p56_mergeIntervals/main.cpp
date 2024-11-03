/*
Runtime 5 ms Beats 98.61%
Memory 22.95 MB Beats 74.71%
*/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << ",";
        cout << "  ";
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            auto& last = res.back();
            if (last[1] < intervals[i][0]) {
                res.push_back(intervals[i]);
                continue;
            }
            //last[0] = min(last[0], intervals[i][0]); No need, since it's sorted.
            last[1] = max(last[1], intervals[i][1]);
        }
        return res;
    }
};

int main()
{
#if 0
    vector<vector<int>> intervals = { {1,3},{2,6},{8,10},{15,18} };
    vector<vector<int>> intervals = { {1,4},{4,5} };
#endif
    Solution s;
    vector<vector<int>> intervals = { {1,3},{2,6},{8,10},{15,18} };

    for (auto v : intervals)
        s.printVec(v);
    cout << endl;

    vector<vector<int>> output = s.merge(intervals);

    for (auto v : output)
        s.printVec(v);
    cout << endl;
    return 0;
}
