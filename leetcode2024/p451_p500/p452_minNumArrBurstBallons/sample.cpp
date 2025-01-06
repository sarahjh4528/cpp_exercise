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
1 <= points.length <= 10^5
points[i].length == 2
-2^31 <= xstart < xend <= 2^31 - 1
*/
    int findMinArrowShots(vector<vector<int>>& points) {
    }
};

int main()
{
#if 0
    vector<vector<int>> points = { {10,16},{2,8},{1,6},{7,12} };
    vector<vector<int>> points = { {1,2},{3,4},{5,6},{7,8} };
    vector<vector<int>> points = { {1,2},{2,3},{3,4},{4,5} };
#endif
    vector<vector<int>> points = { {1,2},{2,3},{3,4},{4,5} };
    Solution s;

    for (auto row : points)
        s.printVec(row);
    cout << endl;

    int output = s.findMinArrowShots(points);
    cout << "Minumum arrows: " << output << endl;

    return 0;
}
