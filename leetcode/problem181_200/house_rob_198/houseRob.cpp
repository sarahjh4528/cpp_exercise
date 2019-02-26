#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[nums.size() - 1];
    }
};
int main()
{
#if 0
    vector<int> mList = {1,2,3,1};
    vector<int> mList = {2,7,9,3,1};
#endif
    vector<int> mList = {2,1,1,2};
    Solution s;

    int maxR = s.rob(mList);
    cout << "Maximum rob: " << maxR << endl;
    return 0;
}
