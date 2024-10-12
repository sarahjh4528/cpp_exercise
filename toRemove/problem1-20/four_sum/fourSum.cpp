#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    void printVec(vector<vector<int>> &vec) {
        for (auto v : vec) {
            for (auto i : v) {
                cout << i << " ";
            }
            cout << endl;
        }
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> out;
        sort(nums.begin(), nums.end());
        for (int i = 0 ; i < nums.size(); ++i ) {
            for (int j = i + 1; j < nums.size(); ++j) {
                int newTarget = target - nums[i] - nums[j];
                int front = j + 1, back = nums.size() - 1;
                while (front < back) {
                    int sum = nums[front] + nums[back];
                    if (sum < newTarget) {
                        ++front;
                    } else if (sum > newTarget) {
                        --back;
                    } else {
                        vector<int> foundSet = {nums[i], nums[j], nums[front], nums[back]};
                        out.push_back(foundSet);
                        while (front < back && nums[front + 1] == nums[front])
                            ++front;
                        while (front < back && nums[back - 1] == nums[back])
                            --back;
                        ++front;
                        --back;
                    }
                }
                while (j + 1 < nums.size() - 1 && nums[j+1] == nums[j])
                    ++j;
            }
            while (i + 1 < nums.size() - 1 && nums[i+1] == nums[i])
                ++i;
        }

        return out;
    }
};

int main()
{
    vector<int> input = {1, 0, -1, 0, -2, 2};
    Solution s;

    vector<vector<int>> output = s.fourSum(input, 0);
    s.printVec(output);

    return 0;
}
