/*
Constraints:

1 <= intervals.length <= 10^4
intervals[i].length == 2
0 <= starti <= endi <= 10^4
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
    }
};

int main()
{
#if 0
    vector<vector<int>> intervals = { {1,3},{2,6},{8,10},{15,18} };
    vector<vector<int>> intervals = { {1,4},{4,5} };
#endif
    Solution s;
    vector<vector<int>> intervals = { {1,4},{4,5} };

    for (auto v : intervals)
        s.printVec(v);
    cout << endl;

    vector<vector<int>> output = s.merge(intervals);

    for (auto v : output)
        s.printVec(v);
    cout << endl;
    return 0;
}
