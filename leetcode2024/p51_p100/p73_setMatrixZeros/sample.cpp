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
*/
    void setZeroes(vector<vector<int>>& matrix) {
    }
};

int main()
{
#if 0
    vector<vector<int>> matrix = { {1,1,1},{1,0,1},{1,1,1} };
    vector<vector<int>> matrix = { {0,1,2,0},{3,4,5,2},{1,3,1,5} };
#endif
    vector<vector<int>> matrix = { {1,1,1},{1,0,1},{1,1,1} };
    Solution s;

    s.setZeroes(matrix);
    for (auto row : matrix)
        s.printVec(row);
    return 0;
}
