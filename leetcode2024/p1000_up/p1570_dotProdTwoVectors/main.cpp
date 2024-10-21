/*
Runtime 133 ms Beats 86.65%
Memory 174.08 MB Beats 33.67%
*/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class SparseVector {
    unordered_map<int, int> map;
public:
    unordered_map<int, int> getNums() {
        return map;
    }

    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                map[i] = nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        unordered_map vecMap = vec.getNums();
        int res = 1;
        for (auto it = map.begin(); it != map.end(); it++) {
            int i = it->first;
            if (vecMap.count(i))
                res += map[i] * vecMap[i];
        }
        return res;
    }
};


class Solution {
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

};

int main()
{
// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
    vector<vector<int>> nums1 = {
        {1,0,0,2,3},
        {0,1,0,0,0},
        {0,1,0,0,2,0,0}
    };
    vector<vector<int>> nums2 = {
        {0,3,0,4,0},
        {0,0,0,0,2},
        {1,0,0,0,3,0,4}
    };
    Solution s;
    for (int i = 0; i < nums1.size(); i++) {
        SparseVector v1(nums1[i]);
        SparseVector v2(nums2[i]);
        s.printVec(nums1[i]);
        s.printVec(nums2[i]);
        int ans = v1.dotProduct(v2);
        cout << "Dot product: " << ans << endl;
    }

    return 0;
}
