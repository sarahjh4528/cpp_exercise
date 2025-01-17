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
/*
Runtime 20 ms Beats 68.78%
Memory 36.87 MB Beats 68.33%

Time: O(n+m), n: nums1.size(), m: nums2.size();
Space: O(n+m)
*/
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        vector<vector<int>> res(2);
        for (auto it = s1.begin(); it != s1.end(); it++) {
            if (!s2.count(*it))
                res[0].push_back(*it);
        }
        for (auto it = s2.begin(); it != s2.end(); it++) {
            if (!s1.count(*it))
                res[1].push_back(*it);
        }
        return res;
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
