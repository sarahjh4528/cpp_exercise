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
Constraints:

1 <= intervals.length <= 10^4
0 <= starti < endi <= 10^6
*/
    int minMeetingRooms(vector<vector<int>>& intervals) {
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
