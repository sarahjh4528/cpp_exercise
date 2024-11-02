/*
Runtime 132 ms Beats 87.91%
Memory 172.30 MB Beats 68.69%
*/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class SparseVector {
    unordered_map<int, int> smap;
public:
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                smap[i] = nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int res = 0;
        for (auto it = smap.begin(); it != smap.end(); it++) {
            int i = it->first;
            if (vec.smap.count(i))
                res += smap[i] * vec.smap[i];
        }
        return res;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
