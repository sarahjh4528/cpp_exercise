/*
Runtime 9 ms Beats 19.94%
Memory 14.52 MB Beats 8.33%
Fastest solution sort 2 arrays, then loop through array to find same num, add to a set
return vector converted from the set.
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return intersection(nums2, nums1);
        unordered_map<int, int> map;
        for (auto n : nums1)
            map[n] = 1;
        vector<int> res;
        for (auto n : nums2) {
            if (map[n] == 1) {
                res.push_back(n);
                map[n] = 0;
            }
        }
        return res;
    }
};

