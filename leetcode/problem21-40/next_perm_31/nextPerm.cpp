/*
 * class Solution {
 * public:
 *     void nextPermutation(vector<int>& nums) {
 *         
 *     }
 * };
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 * If such arrangement is not possible, it must rearrange it as the lowest possible order
 * (ie, sorted in ascending order).
 * The replacement must be in-place and use only constant extra memory.
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs
 * are in the right-hand column.
 * 
 * 1,2,3 # 1,3,2
 * 3,2,1 # 1,2,3    // case 2
 * 1,1,5 # 1,5,1
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
public:
    void printVec(const vector<int>& nums) {
        for (auto i : nums)
            cout << i << " ";
        cout << endl;
    }
    void nextPermutation(vector<int>& nums) {
        if (nums.empty())
            return;

        int n = nums.size(), nextPStart;
        for (nextPStart = n - 2; nextPStart >= 0; --nextPStart) {
            if (nums[nextPStart] < nums[nextPStart+1])
                break;
        }
        if (nextPStart < 0) {
            // Not finding the turning point, case 2, reverse whole list
            reverse(nums.begin(), nums.end());
        } else {
            int toSwap;
            for (toSwap = n - 1; toSwap > nextPStart; --toSwap) {
                if (nums[nextPStart] < nums[toSwap])
                    break;
            }
            int temp = nums[toSwap];
            nums[toSwap] = nums[nextPStart];
            nums[nextPStart] = temp;
            reverse(nums.begin() + nextPStart + 1, nums.end());
        }
    }
};
int main()
{
    vector<vector<int>> vNums = {
        {1,2,3},
        {3,2,1},
        {6,2,1,5,4,3,0},
        {1,1,5}
    };

    for (auto nums : vNums) {
        Solution s;
        cout << "Current vec: " << endl;
        s.printVec(nums);
        s.nextPermutation(nums);
        cout << "Next permutation: " << endl;
        s.printVec(nums);
    }

    return 0;
}
