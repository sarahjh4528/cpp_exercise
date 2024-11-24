#include<bits/stdc++.h>
#include<iostream>

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
Memory 15.20 MB Beats 72.34%

Same solution as fastest
NOTE: No need to check intervals.size(), as it returns true, following code is the clean code version
*/
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[i-1][1])
                return false;
        }
        return true;
    }
};

int main()
{
#if 0
    vector<vector<int>> intervals = { {0,30},{5,10},{15,20} };
    vector<vector<int>> intervals = { {7,10},{2,4} };
#endif
    vector<vector<int>> intervals = { {7,10},{2,4} };
    Solution s;

    for (auto interval : intervals) {
        s.printVec(interval);
        cout << endl;
    }
    bool output = s.canAttendMeetings(intervals);
    cout << "Can attend: " << output << endl;
    
    return 0;
}
