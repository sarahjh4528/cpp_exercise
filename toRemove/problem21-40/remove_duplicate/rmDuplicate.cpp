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

    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int swapIndex = -1;
        int validElem = nums[0];
        for (int i = 1; i != nums.size(); ++i) {
            if (nums[i] <= validElem) {
                if (swapIndex == -1)
                    swapIndex = i;
                continue;
            } else {
                if (swapIndex != -1) {
                    validElem = nums[i];
                    swap(nums, swapIndex, i);
                    ++swapIndex;
                } else {
                    validElem = nums[i];
                }
            }
        }
        if (swapIndex != -1) {
            nums.erase(nums.begin() + swapIndex, nums.end());
        }
        cout << "After rm duplicate, nums length: " << nums.size() << endl;
        return (nums.size());
    }
};

int main()
{
#if 0
    vector<int> iList = {0,0,1,1,1,2,2,3,3,4};
    vector<int> iList = {};
    vector<int> iList = {1};
    vector<int> iList = {0,1,1,1,2,2,3,3,4};
#endif
    vector<int> iList = {0,1,1,1,2,2,3,3,4};

    Solution s;
    s.printList(iList);
    int length = s.removeDuplicates(iList);
    cout << "Output length: " << length << endl;
    s.printList(iList);
    return 0;
}
