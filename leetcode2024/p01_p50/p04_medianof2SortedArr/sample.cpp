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

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    }
};

int main()
{
    vector<vector<int>> vnums1 = {
        {1,3},
        {1,2}
    };
    vector<vector<int>> vnums2 = {
        {2},
        {3,4}
    };
    Solution s;

    for (int i = 0; i < vnums1.size(); i++) {
        s.printVec(vnums1[i]);
        s.printVec(vnums2[i]);
        double output = s.findMedianSortedArrays(vnums1[i],vnums2[i]);
        cout << "Median of above arrays: " << output << endl;
    }
    return 0;
}
