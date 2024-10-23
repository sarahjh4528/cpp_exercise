/*
Runtime 48 ms Beats 95.51%
Memory 27.53 MB Beats 51.53%
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        if (n == 3) {
            if (nums[0] + nums[1] + nums[2] == 0)
                res.push_back(nums);
            return res;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-2; i++) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            int low = i+1, high = n-1;
            while (low < high) {
                int sum = nums[i] + nums[low] + nums[high];
                if (sum == 0) {
                    res.push_back({nums[i], nums[low], nums[high]});
                    while (low < high && nums[low] == nums[low+1])
                        low++;
                    low++;
                    high--;
                } else if (sum > 0)
                    high--;
                else
                    low++;
            }
        }
        return res;
    }
};
