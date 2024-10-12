#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    void printVec(vector<int>& indices) {
        if (!indices.empty())
            cout << "[" << indices[0] << ", " << indices[1] << "]" << endl;
    }

    bool foundMatch(vector<int>& nums, int start, int end, int target, int& secIndex) {
        if (start >= end) {
            secIndex = end;
            return (nums[end] == target)? true : false;
        }

        int mid = (end - start) / 2 + start;
        if (nums[mid] == target) {
            secIndex = mid;
            return true;
        } else if (nums[mid] < target) {
            return foundMatch(nums, mid + 1, end, target, secIndex);
        } else {
            return foundMatch(nums, start, mid - 1, target, secIndex);
        }
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i) {
            int secIndex = 0;
            if (foundMatch(numbers, i+1, numbers.size()-1, target-numbers[i], secIndex))
                return {i+1, secIndex+1};
        }
        return {};
    }
};
int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution s;

    vector<int> indices = s.twoSum(nums, target);
    s.printVec(indices);
    return 0;
}
