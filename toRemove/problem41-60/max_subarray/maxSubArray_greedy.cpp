#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

class Solution
{
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, min = 0, res = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            res = (sum - min > res)? sum - min : res;
            min = (sum < min)? sum : min;
        }
        return res;
    }
};

int main()
{
#if 0
    vector<int> iList = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> iList = {-2,-1};
#endif
    vector<int> iList = {-2,1,-3,4,-1,2,1,-5,4};
    Solution s;


    int maxSum = s.maxSubArray(iList);
    cout << maxSum << endl;
    return 0;
}
