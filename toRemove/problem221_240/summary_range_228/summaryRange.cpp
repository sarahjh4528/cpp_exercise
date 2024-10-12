#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string getRange(int start, int end) {
        if (start == end)
            return to_string(start);
        else
            return to_string(start) + "->" + to_string(end);
    }
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty())
            return {};

        if (nums.size() == 1)
            return {getRange(nums[0], nums[0])};

        vector<string> ret;
        int rStart = nums[0];
        int nLen = nums.size();
        for (int i = 1; i < nLen; ++i) {
            if ((long long)nums[i] - (long long)nums[i-1] > 1) {
                ret.push_back(getRange(rStart, nums[i-1]));
                rStart = nums[i];
            }
        }
        ret.push_back(getRange(rStart, nums[nLen-1]));
        return ret;
    }
};

int main()
{
#if 0
    vector<int> nums = {0,1,2,4,5,7};
    vector<int> nums = {0,2,3,4,6,8,9};
#endif
    vector<int> nums = {0,1,2,4,5,7};

    Solution s;
    for (auto num : nums)
        cout << num << " ";
    cout << endl;

    vector<string> rangeSummary = s.summaryRanges(nums);
    for (auto str : rangeSummary)
        cout << str << " ";
    cout << endl;
    return 0;
}
