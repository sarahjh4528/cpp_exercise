/*
Runtime 4 ms Beats 93.95%
Memory 14.34 MB Beats 36.67%
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map.count(nums[i]))
                return {i, map[nums[i]]};
            else
                map[target-nums[i]] = i;
        }
        return {};
    }
};
