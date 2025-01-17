#include<bits/stdc++.h>
#include<iostream>
#include<unordered_set>
using namespace std;

class Solution {
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

/*
1 <= nums1.length, nums2.length <= 1000
-1000 <= nums1[i], nums2[i] <= 1000
*/
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    }

};

int main()
{
    vector<vector<int>> vnums1 = {
        {1,2,3},
        {1,2,3,3}
    };
    vector<vector<int>> vnums2 = {
        {2,4,6},
        {1,1,2,2}
    };
    Solution s;

    for (int i = 0; i < vnums1.size(); i++) {
        cout << "Input arrays: " << endl;
        s.printVec(vnums1[i]);
        s.printVec(vnums2[i]);
        vector<vector<int>> output = s.findDifference(vnums1[i], vnums2[i]);
        for (auto row : output)
            s.printVec(row);
    }

    return 0;
}
