#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        if (nums.empty())
            return {};

        vector<int> missingNums;
        /* scan all nums in nums, and use it as index to mark the num exists by its negative value.
         * However, the valus might be later for index, therefore need to use its absolute value
         * instead. For the numbers missing, the corresponding index won't get marked, the number
         * at that position will be positive.
         */
        for (auto i : nums) {
            int n = abs(i) - 1;
            nums[n] = (nums[n] > 0)? -nums[n] : nums[n];
        }

        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] > 0)
                missingNums.push_back(j + 1);    // No speed improvement if replaced with emplace_back
        }
        return missingNums;
    }
};

int main()
{
    vector<vector<int>> vNums = {
        {4,3,2,7,8,2,3,1},
        {1,1,2,2},
        {1,1},
    };

    Solution s;
    for (auto nums : vNums) {
        vector<int> missNums = s.findDisappearedNumbers(nums);
        for (auto i : missNums)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
