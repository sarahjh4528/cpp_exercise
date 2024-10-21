/*
Runtime 0 ms Beats 100.00%
Memory 21.94 MB Beats 25.69%
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i0 = 0, cur = 0, n = nums.size();
        while (cur < n) {
            if (nums[cur] != 0) {
                nums[i0] = nums[cur];
                i0++;
            }             
            cur++;
        }
        while (i0 < n)
            nums[i0++] = 0;
    }
};
