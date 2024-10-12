#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    void printList(vector<int>& nums) {
        for (auto i : nums)
            cout << i << " ";
        cout << endl;
    }

    void swap(vector<int>& nums1, int i, vector<int>& nums2, int j) {
        int temp = nums1[i];
        nums1[i] = nums2[j];
        nums2[j] = temp;
    }

    void insertionSort(vector<int>& nums) {
        int index = 0;
        while (index < nums.size() - 1) {
            if (nums[index] > nums[index + 1]) 
                swap(nums, index, nums, (index + 1));
            else
                break;
            ++index;
        }
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0)
            return;

        int i1 = 0;
        while (i1 < m) {
            if (nums1[i1] <= nums2[0]) {
                ++i1;
            } else {
                swap(nums1, i1, nums2, 0);
                insertionSort(nums2);
                ++i1;
            }
        }
        copy(nums2.begin(), nums2.end(), nums1.begin()+m);
    }
};

int main()
{
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};

    Solution s;
    s.printList(nums1);
    s.printList(nums2);
    s.merge(nums1, 3, nums2, 3);
    s.printList(nums1);
    return 0;
}
