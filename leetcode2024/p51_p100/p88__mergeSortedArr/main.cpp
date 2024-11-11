/*
Runtime 0 ms Beats 100.00%
Memory 11.28 MB Beats 67.08%
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

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1;
        int cur = m+n-1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j])
                nums1[cur--] = nums1[i--];
            else
                nums1[cur--] = nums2[j--];
        }
        while (j >= 0)
            nums1[cur--] == nums2[j--];
    }

};

int main()
{
    vector<int> nums1 = {0}, nums2 = {1};
    Solution s;

    s.merge(nums1, 0, nums2, 1);
    s.printVec(nums1);
    return 0;
}
