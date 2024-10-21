/*
Runtime 29 ms Beats 35.51%
Memory 94.64 MB Beats 87.37%
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1len = nums1.size(), n2len = nums2.size();
        if (n1len > n2len)
            return findMedianSortedArrays(nums2, nums1);  // Make sure binary search on smaller arrays.
        int low = 0, high = n1len;
        while (low <= high) {
            int mid1 = (low + high) / 2;
            int mid2 = (n1len + n2len + 1) / 2 - mid1;
            int maxX = (mid1 == 0)? INT_MIN : nums1[mid1-1];
            int minX = (mid1 == n1len)? INT_MAX : nums1[mid1];
            int maxY = (mid2 == 0)? INT_MIN : nums2[mid2-1];
            int minY = (mid2 == n2len)? INT_MAX : nums2[mid2];
            if (maxX <= minY && maxY <= minX) {
                if ((n1len + n2len) % 2 == 0)
                    return ((double) (max(maxX, maxY) + min(minX, minY)))/ 2;
                else
                    return (double) (max(maxX, maxY));
            } else if (maxX < minY) {
                low = mid1 + 1;
            } else {
                high = mid1 - 1;
            }
        }
        throw invalid_argument("Invalid input arrays");
    }
};
