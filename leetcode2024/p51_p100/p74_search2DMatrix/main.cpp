/*
Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-10^4 <= matrix[i][j], target <= 10^4
*/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

/*
Runtime 0 ms Beats 100.00%
Memory 13.21 MB Beats 7.71%
*/
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int low = 0, high = row * col - 1, i, j;
        while (low <= high) {
            int mid = (low + high) / 2;
            i = mid / col;
            j = mid % col;
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};

int main()
{
#if 0
    vector<vector<int>> matrix = {
        {1,3,5,7},{10,11,16,20},{23,30,34,60}
    };
    vector<int> vt = {3, 13};
#endif
    vector<vector<int>> matrix = { {1,1} };
    vector<int> vt = {2};
    Solution s;

    for (auto row : matrix)
        s.printVec(row);

    for (auto target : vt) {
        bool output = s.searchMatrix(matrix, target);
        cout << "Find target " << target << " : " << output << endl;
    }
    return 0;
}
