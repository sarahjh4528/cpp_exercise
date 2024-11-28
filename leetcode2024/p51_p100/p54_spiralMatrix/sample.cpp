/*
Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
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

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    }
};

int main()
{
#if 0
    vector<vector<int>> matrix = { {1,2,3},{4,5,6},{7,8,9} };
    vector<vector<int>> matrix = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
#endif
    vector<vector<int>> matrix = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
    Solution s;

    vector<int> output = s.spiralOrder(matrix);
    s.printVec(output);
    
    return 0;
}
