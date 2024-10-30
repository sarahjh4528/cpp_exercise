/*
Runtime 0 ms Beats 100.00%
Memory 16.45 MB Beats 7.05%
*/
class Solution {
    int binarySearch(vector<int>& nums, int target, bool findLow) {
        int low = 0, high = nums.size() - 1;
        int res = -1;
        while (low <= high) {
            int mid = (high + low) / 2;
            if (nums[mid] < target)
                low = mid + 1;
            else if (nums[mid] > target)
                high = mid - 1;
            else { // nums[mid] == target
                res = mid;
                if (findLow)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }
        return res;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0 || target > nums[n-1] || target < nums[0])
            return {-1, -1};

        int left = binarySearch(nums, target, true);
        int right = binarySearch(nums, target, false);
        return {left, right};
    }
};
