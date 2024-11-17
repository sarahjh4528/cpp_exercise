/*
Runtime 0 ms Beats 100.00%
Memory 94.82 MB Beats 54.10%
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

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        int n1len = nums1.size(), n2len = nums2.size();
        int total = n1len + n2len;
        int partition = total / 2;
        int left = 0, right = n1len;
        while (left <= right) {
            int mid1 = (left + right) / 2;
            int mid2 = partition - mid1;
            int left1 = (mid1 > 0)? nums1[mid1-1] : INT_MIN;
            int left2 = (mid2 > 0)? nums2[mid2-1] : INT_MIN;
            int right1 = (mid1 < n1len)? nums1[mid1] : INT_MAX;
            int right2 = (mid2 < n2len)? nums2[mid2] : INT_MAX;
            if (left1 <= right2 && left2 <= right1) {
                if (total % 2)
                    return min(right1, right2);
                else
                    return (double(max(left1, left2)) + min(right1, right2)) / 2;
            } else if (left1 > right2)
                 right = mid1 - 1;               
            else
                left = mid1 + 1;
        }
        return 0.0;
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
