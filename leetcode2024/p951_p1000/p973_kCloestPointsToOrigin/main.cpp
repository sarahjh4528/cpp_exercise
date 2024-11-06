/*
Runtime 46 ms Beats 65.56%
Memory 66.29 MB Beats 81.18%

Same design as in tutorial
*/
#include<bits/stdc++.h>
#include<iostream>
#include<queue>

using namespace std;

class Solution {
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < points.size(); i++) {
            int dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            pq.push(make_pair(dist, i));
            if (pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> res;
        while (!pq.empty()) {
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        return res;
    }
};

int main()
{
#if 0
    vector<vector<int>> points = {{1,3},{-2,2}};
    int k = 1;

    vector<vector<int>> points = {{3,3},{5,-1},{-2,4}};
    int k = 2;
#endif
    vector<vector<int>> points = {{3,3},{5,-1},{-2,4}};
    int k = 2;
    Solution s;

    vector<vector<int>> output = s.kClosest(points, k);
    cout << "Input: " << endl;
    for (auto row : points)
        s.printVec(row);

    cout << k << " closest points: " << endl;
    for (auto row : output)
        s.printVec(row);
    return 0;
}
