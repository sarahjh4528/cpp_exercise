#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using std::cout;
using std::endl;
using std::vector;
using std::abs;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3)
            return 0;

        sort(nums.begin(), nums.end());

        int closestSum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i != nums.size(); ++i) {
            int front = i + 1, back = nums.size() - 1;
            int curTarget = target - nums[i];
            while (front < back) {
                int twoSum = nums[front] + nums[back];
                int threeSum = twoSum + nums[i];
                if (threeSum == target) {
                    cout << target << endl;
                    return target;
                } else if (twoSum > curTarget) {
                    if (abs(threeSum - target) < abs(closestSum - target))
                        closestSum = threeSum;
                    while (front < back && nums[back - 1] == nums[back])
                        --back;
                    --back;
                } else {
                    if (abs(threeSum - target) < abs(closestSum - target))
                        closestSum = threeSum;
                    while (front < back && nums[front + 1] == nums[front])
                        ++front;
                    ++front;
                }
            }
            if (i + 1 < nums.size() && nums[i+1] == nums[i])
                ++i;
        }
        cout << closestSum << endl;
        return closestSum;
    }
};

int main()
{
    Solution s;
#if 0
    vector<int> input = {-1, 2, 1, -4};
    s.threeSumClosest(input, 1);

    vector<int> input = {0, 2, 1, -3};    // -3, 0, 1, 2
    s.threeSumClosest(input, 1);

    vector<int> input = {-1,0,1,1,55};      // -1, 0, 1, 1, 55
    s.threeSumClosest(input, 3);

    vector<int> input = {1,2,4,8,16,32,64,128};
    s.threeSumClosest(input, 82);
#else
    vector<int> input = {0, 2, 1, -3};    // -3, 0, 1, 2
    s.threeSumClosest(input, 1);
#endif

    return 0;
}
