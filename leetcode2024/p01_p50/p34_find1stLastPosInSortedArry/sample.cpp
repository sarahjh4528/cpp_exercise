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

    vector<int> searchRange(vector<int>& nums, int target) {
    }

};

int main()
{
    vector<vector<int>> vnums = {
        {5,7,7,8,8,10},
        {5,7,7,8,8,10},
        {}
    };
    vector<int> vtarget = {8,6,0};
    Solution s;

    for (int i = 0; i < vtarget.size(); i++) {
        s.printVec(vnums[i]);
        vector<int> output = s.searchRange(vnums[i], vtarget[i]);
        cout << "Position of " << vtarget[i] << " in arr : " << endl;
        s.printVec(output);
    }
    return 0;
}
