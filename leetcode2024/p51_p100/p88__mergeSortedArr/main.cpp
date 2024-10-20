/*
Runtime 0 ms Beats 100.00%
Memory 11.28 MB Beats 67.06%
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = nums1.size()-n-1, j = n-1, cur = nums1.size()-1;
        while (i >= 0 && j >= 0) {
            if (nums2[j] > nums1[i]) {
                nums1[cur] = nums2[j];
                j--;
            } else {
                nums1[cur] = nums1[i];
                i--;
            }
            cur--;
        }
        while (j >= 0)
            nums1[cur--] = nums2[j--];
    }
};
