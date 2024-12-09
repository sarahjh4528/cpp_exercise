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

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    }
};

int main()
{
#if 0
    vector<vector<int>> matrix = { {1,3,5,7},{10,11,16,20},{23,30,34,60} };
    vector<int> vt = {3, 13};
    vector<vector<int>> matrix = { {1,1} };
    vector<int> vt = {2};
#endif
    Solution s;
    vector<vector<int>> matrix = { {1,3,5,7},{10,11,16,20},{23,30,34,60} };
    vector<int> vt = {3, 13};

    for (auto row : matrix)
        s.printVec(row);

    for (auto target : vt) {
        bool output = s.searchMatrix(matrix, target);
        cout << "Find target " << target << " : " << output << endl;
    }
    return 0;
}
