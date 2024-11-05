#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
    int getElementCount(vector<vector<int>>& matrix, int val) {
        int res = 0, n = matrix.size();
        for (int i = 0; i < n; i++) {
            auto& nums = matrix[i];
            res += (upper_bound(nums.begin(), nums.end(), val) - nums.begin());
        }
        return res;
    }

public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

/*
Design: Binary Search on value, then count whether there are kth elements >= val.
Runtime 3 ms Beats 73.15%
Memory 15.74 MB Beats 96.50%

Fastest solution same design, instead of call function, move codes in getElementCount back to kthSmallest
*/
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n-1][n-1];  // Max num is at the matrix last row, last columnu
        int res = matrix[0][0];

        while (low <= high) {
            int mid = low + (high-low)/2;
            int count = getElementCount(matrix, mid);
            if (count >= k) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
};

int main()
{
#if 0
    vector<vector<int>> matrix = {
        {1,5,9},{10,11,13},{12,13,15}
    };
    int k = 8;

    vector<vector<int>> matrix = {
        {-5}
    };
    int k = 1;
#endif
    vector<vector<int>> matrix = {
        {1,5,9},{10,11,13},{12,13,15}
    };
    int k = 8;
    Solution s;

    int output = s.kthSmallest(matrix, k);
    for (auto row : matrix)
        s.printVec(row);

    cout << k << "th smallest element in matrix: " << output << endl;
    return 0;
}
