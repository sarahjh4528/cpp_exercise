/*
Runtime 4 ms Beats 99.71%
Memory 27.00 MB Beats 49.95%
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0], cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == candidate)
                cnt++;
            else
                cnt--;
            if (cnt == -1) {
                candidate = nums[i];
                cnt = 1;
            }
        }
        return candidate;
    }
};
