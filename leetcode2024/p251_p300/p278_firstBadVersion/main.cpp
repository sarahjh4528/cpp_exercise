#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
    // The API isBadVersion is defined for you.
    // bool isBadVersion(int version);
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

/*
Constraints:
1 <= bad <= n <= 2^31 - 1
*/
    int firstBadVersion(int n) {
        if (n == 1)
            return 1;
        int low = 1, high = n;
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (isBadVersion(mid)) { 
                if (!isBadVersion(mid-1))
                    return mid;
                else
                    high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }

};

int main()
{
    Solution s;

    vector<int> input = {1,2,3,4,5,6};
    s.printVec(input);
    return 0;
}
