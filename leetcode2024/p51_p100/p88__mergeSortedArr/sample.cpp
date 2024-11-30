/*
Constraints:

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-10^9 <= nums1[i], nums2[j] <= 10^9
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
