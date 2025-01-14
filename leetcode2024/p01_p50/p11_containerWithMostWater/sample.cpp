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

/*
n == height.length
2 <= n <= 10^5
0 <= height[i] <= 10^4
*/
    int maxArea(vector<int>& height) {
    }
};

int main()
{
    vector<vector<int>> vheight = {
        {1,8,6,2,5,4,8,3,7},
        {1,1}
    };
    Solution s;

    for (auto height : vheight) {
        s.printVec(height);
        int output = s.maxArea(height);
        cout << "Max area: " << output << endl;
    }

    return 0;
}
