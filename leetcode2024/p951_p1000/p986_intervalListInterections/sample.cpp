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
