#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
    }

/*
Runtime 35 ms Beats 59.28%
Memory 24.27 MB Beats 18.84%
*/
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 1)
            return 1;
        int res = 2;  // 2 points, at least there's a line with 2 points.
        for (int i = 0; i < n; i++) {  // For each point, cal atan value of other points
            unordered_map<double, int> cnt;  // Count points with same atan value
            for (int j = 0; j < n; j++) {
                if (i != j) { // Do not calculate atan of the same point.
                    double k = atan2(points[j][1]-points[i][1], points[j][0]-points[i][0]);
                    cnt[k]++;
                }
            }
            for (auto it = cnt.begin(); it != cnt.end(); it++)
                res = max(res, it->second+1);
        }
        return res;
        
    }
};

int main()
{
#if 0
    vector<vector<int>> points = { {1,1},{2,2},{3,3} };
    vector<vector<int>> points = { {1,1},{3,2},{5,3},{4,1},{2,3},{1,4} };
#endif
    vector<vector<int>> points = { {1,1},{2,2},{3,3} };
    Solution s;

    for (auto pt : points)
        s.printVec(pt);
    cout << endl;
    int output = s.maxPoints(points);
    cout << "Maximum points on a line: " << output << endl;
    return 0;
}
