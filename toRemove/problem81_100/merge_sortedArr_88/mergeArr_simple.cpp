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

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Compare from end
        int i1 = m - 1, i2 = n - 1, toFill = nums1.size() - 1;
        while (i1 >= 0 && i2 >= 0 ) {
            if (nums1[i1] >= nums2[i2]) {
                nums1[toFill] = nums1[i1];
                --i1;
            } else {
                nums1[toFill] = nums2[i2];
                --i2;
            }
            --toFill;
        }
        if (i2 >= 0)
            copy(nums2.begin(), nums2.begin()+i2+1, nums1.begin());
    }
};

int main()
{
#if 0
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};

    vector<int> nums1 = {7,8,9,0,0,0};
    vector<int> nums2 = {2,5,6};

    vector<int> nums1 = {0};
    vector<int> nums2 = {1};
#endif
    vector<int> nums1 = {0};
    vector<int> nums2 = {1};

    Solution s;
    s.printList(nums1);
    s.printList(nums2);
    s.merge(nums1, 0, nums2, 1);
    s.printList(nums1);
    return 0;
}
