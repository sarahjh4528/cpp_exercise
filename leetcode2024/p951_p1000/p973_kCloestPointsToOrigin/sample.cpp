#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
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
