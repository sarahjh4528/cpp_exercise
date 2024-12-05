/*
Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-2^31 <= matrix[i][j] <= 2^31 - 1
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
Scan through matrix rows, cols, set 1st cell in row/col to 0 if there's 0 at the row/col.
Therefore, need to scan 1st row/col to see if we need to set 1st row/col to be zeros.

Based on 0s in 1st cell in row/col of the matrix, set entire row/col to zero.

Runtime 0 ms Beats 100.00%
Memory 18.44 MB Beats 10.05%

Time: O(m*n), Space: O(1)
*/
    void setZeroes(vector<vector<int>>& matrix) {
        bool c1zero = false;
        int row = matrix.size(), col = matrix[0].size();
        for (int i = 0; i < row; i++) {
            if (matrix[i][0] == 0)
                c1zero = true;
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        if (matrix[0][0] == 0) {
            int j = 0;
            while (j < col)
                matrix[0][j++] = 0;
        }
        if (c1zero) {
            int i = 0;
            while (i < row)
                matrix[i++][0] = 0;
        }
    }
};

int main()
{
#if 0
    vector<vector<int>> matrix = { {1,1,1},{1,0,1},{1,1,1} };
    vector<vector<int>> matrix = { {0,1,2,0},{3,4,5,2},{1,3,1,5} };
#endif
    vector<vector<int>> matrix = { {0,1,2,0},{3,4,5,2},{1,3,1,5} };
    Solution s;

    s.setZeroes(matrix);
    for (auto row : matrix)
        s.printVec(row);
    return 0;
}
