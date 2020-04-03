#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        int sum = INT_MIN, curSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            curSum += nums[i];
            sum = max(sum, curSum);
            curSum = (curSum > 0)? curSum : 0;
        }
        return sum;
    }
};

int main()
{
    vector<int> input = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    Solution s;
    int sum = s.maxSubArray(input);
    cout << "Max subarray sum : " << sum << endl;
    return 0;
}
