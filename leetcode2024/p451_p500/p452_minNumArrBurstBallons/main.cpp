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
/*
Runtime 37 ms Beats 94.27%
Memory 93.89 MB Beats 64.96%
*/
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](auto& p1, auto& p2) {
            return (p1[1] < p2[1]);
        });
        int res = 1, curEnd = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > curEnd) {
                res++;
                curEnd = points[i][1];
            }
        }
        return res;
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
