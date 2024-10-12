// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

/*
Runtime: 4 ms, faster than 100.00% of C++ online submissions for First Bad Version.
Memory Usage: 8.4 MB, less than 5.12% of C++ online submissions for First Bad Version.
 */
class Solution {
public:
    int getBadVersion(int start, int end) {
        if (start >= end) {
            return isBadVersion(end)? end : -1;
        }
        int mid = (end - start) / 2 + start;
        if (isBadVersion(mid)) {
            // First bad version at mid and before
            int badV = getBadVersion(start, mid - 1);
            if (badV == -1)
                return mid;
            else
                return badV;
        } else {
            return getBadVersion(mid + 1, end);
        }
    }
    int firstBadVersion(int n) {
        return getBadVersion(0, n);
    }
};
