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
/*
Runtime 1 ms Beats 46.07%
Memory 62.92 MB Beats 18.80%
*/
    int maxArea(vector<int>& height) {
        int i = 0, n = height.size(), j = n-1;
        int res = 0, h = 0;
        while (i < j) {
            h = min(height[i], height[j]);
            res = max(res, h * (j-i));
            if (height[i] <= height[j])
                i++;
            else
                j--;
        }
        return res;
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
