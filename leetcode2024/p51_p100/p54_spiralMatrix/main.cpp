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
        int top = 0, bottom = matrix.size()-1;
        int left = 0, right = matrix[0].size()-1;
        vector<int> res;

        while (top <= bottom && left <= right) {
            // Go right
            for (int i = left; i <= right; i++)
                res.push_back(matrix[top][i]);
            top++;

            // Go down
            for (int i = top; i <= bottom; i++)
                res.push_back(matrix[i][right]);
            right--;

            // Go left
            if (top <= bottom) {
                for (int i = right; i >= left; i--)
                    res.push_back(matrix[bottom][i]);
                bottom--;
            }

            // Go up
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    res.push_back(matrix[i][left]);
                left++;
            }
        }
        return res;
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
