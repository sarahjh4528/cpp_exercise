#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    void printList(vector<int>& nums) {
        for (auto i : nums) {
            cout << i << " ";
        }
        cout << endl;
    }

    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    int removeElement(vector<int>& nums, int val) {
        if (nums.empty())
            return 0;

        int swapIndex = -1;
        int fIndex = 0, bIndex = nums.size() - 1;
        while (fIndex <= bIndex) {
            if (nums[fIndex] == val) {
                while (fIndex < bIndex && nums[bIndex] == val)
                    --bIndex;
                if (fIndex == bIndex) {
                    // All elem with val removed, remove elem at fIndex as well.
                    --bIndex;
                    break;
                } else {
                    swap(nums, fIndex, bIndex);
                    --bIndex;
                }
            }
            ++fIndex;
        }
        return (bIndex + 1);
    }
};

int main()
{
#if 0
    vector<int> iList = {3,2,2,3};
    vector<int> iList = {3,3};
    vector<int> iList = {3,3,2};
    vector<int> iList = {2,3,2,2};
    vector<int> iList = {2,2,3,3};
    int val = 3;
    vector<int> iList = {0,1,2,2,3,0,4,2};
    int val = 2;
#endif
    Solution s;

    vector<int> iList = {2,2,3,3};
    int val = 3;

    s.printList(iList);
    int output = s.removeElement(iList, val);
    s.printList(iList);

    cout << "Remove " << val << ", Output length: " << output << endl;
    return 0;
}
