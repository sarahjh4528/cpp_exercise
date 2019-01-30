#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

class Solution
{
public:
    int searchInsertWithIndex(vector<int>& nums, int target, int start, int end) {
        if (start == end)
            return (target <= nums[start])? start : start + 1;

        int midpoint = (end - start) / 2 + start;
        if (target == nums[midpoint]) {
            return midpoint;
        } else if (target < nums[midpoint]) {
            if (midpoint > start)
                return searchInsertWithIndex(nums, target, start, midpoint - 1);
            else
                return midpoint;
        } else {
            return searchInsertWithIndex(nums, target, midpoint + 1, end);
        }
    }

    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty() || target <= nums[0])
            return 0;

        int numSize = nums.size();
        if (target >= nums[numSize - 1])
            return (target == nums[numSize - 1])? numSize - 1 : numSize;

        return searchInsertWithIndex(nums, target, 0, numSize - 1);
    }
};
int main()
{
#if 0
    vector<int> iList = {1,3,5,6};
    int target = 5;
    vector<int> iList = {1,3,5,6};
    int target = 2;
    vector<int> iList = {1,3,5,6};
    int target = 7;
    vector<int> iList = {1,3,5,6};
    int target = 0;
#endif
    vector<int> iList = {1,3,5,6};
    int target = 0;

    for (auto i : iList) {
        cout << i << " ";
    }
    cout << endl;

    Solution s;
    int insertIndex = s.searchInsert(iList, target);
    cout << "Target: " << target << ", Insert index : " << insertIndex << endl;
    return 0;
}
