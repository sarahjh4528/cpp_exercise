#include<bits/stdc++.h>
#include<iostream>
#include<queue>

using namespace std;

class Solution {
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << ", ";
    }
/*
Runtime 0 ms Beats 100.00%
Memory 16.60 MB Beats 29.83%
*/
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int res = -1;
        for (auto v : intervals) {
            if (!pq.empty() && v[0] >= pq.top())
                pq.pop();
            pq.push(v[1]);
            res = max(res, (int)pq.size());
        }
        return res;
    }
};

int main()
{
#if 0
    vector<vector<int>> intervals = { {0,30},{5,10},{15,20} };
    vector<vector<int>> intervals = { {7,10},{2,4} };
#endif
    vector<vector<int>> intervals = { {0,30},{5,10},{15,20} };
    Solution s;

    int output = s.minMeetingRooms(intervals);
    for (auto v : intervals)
        s.printVec(v);
    cout << endl;
    cout << "Minimum number of rooms required: " << output << endl;
    return 0;
}
