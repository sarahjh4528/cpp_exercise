#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

class Solution
{
public:
    int getMaxSum(vector<int>& nums, int start, int end) {
        int maxSum = nums[start], sum = nums[start];
        for (int i = start + 1; i <= end; ++i) {
            sum += nums[i];
            maxSum = (maxSum < sum)? sum : maxSum;
        }
        return maxSum;
        
    }

    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        int maxSum = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            int sum = getMaxSum(nums, i, nums.size() - 1);
            maxSum = (maxSum > sum)? maxSum : sum;
        }
        return maxSum;
    }
};

int main()
{
#if 0
    vector<int> iList = {-2,1,-3,4,-1,2,1,-5,4};
#endif
    vector<int> iList = {-2,-1};
    Solution s;


    int maxSum = s.maxSubArray(iList);
    cout << maxSum << endl;
    return 0;
}
