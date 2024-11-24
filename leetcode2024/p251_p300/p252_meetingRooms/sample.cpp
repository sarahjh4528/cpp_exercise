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

    bool canAttendMeetings(vector<vector<int>>& intervals) {
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
