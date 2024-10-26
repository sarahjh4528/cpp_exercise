/*
Runtime 0 ms Beats 100.00%
Memory 22.59 MB Beats 63.64%
*/
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

    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int sz1 = firstList.size(), sz2 = secondList.size();
        if (sz1 == 0 || sz2 == 0)
            return {};

        vector<vector<int>> res;
        int i = 0, j = 0;
        while (i < sz1 && j < sz2) {
            int lo = max(firstList[i][0], secondList[j][0]);
            int hi = min(firstList[i][1], secondList[j][1]);
            if (lo <= hi)
                res.push_back({lo, hi});

            if (firstList[i][1] < secondList[j][1])
                i++;
            else
                j++;
        }

        return res;
    }

};

int main()
{
    vector<vector<int>> firstList = { {0,2},{5,10},{13,23},{24,25} };
    vector<vector<int>> secondList = { {1,5},{8,12},{15,24},{25,26} };
    Solution s;

    vector<vector<int>> output = s.intervalIntersection(firstList, secondList);
    for (auto l : output)
        s.printVec(l);
    return 0;
}
