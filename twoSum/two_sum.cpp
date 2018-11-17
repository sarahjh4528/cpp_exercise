#include<iostream>
#include<vector>

using std::vector;

class Solution {
private:
    int found(vector<int>& nums, int num) {
        for (int i = 0; i < nums.size(); ++i) {
            if (num == nums[i])
                return i;
        }
        return 0;
    }
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices;
        int secondIndex = 0;
        for (int i = 0; i < nums.size(); ++i) {
            secondIndex = found(nums, target - nums[i]);
            if (secondIndex) {
                indices.push_back(i);
                indices.push_back(secondIndex);
                return indices;
            }
        }
    }
};

int main() {
    vector<int> samplesIn = {2, 7, 11, 15};
    Solution s;
    vector<int> indices;
    indices = s.twoSum(samplesIn, 9);
    std::cout << indices[0] << ", " << indices[1] << std::endl;
    return 0;
}
