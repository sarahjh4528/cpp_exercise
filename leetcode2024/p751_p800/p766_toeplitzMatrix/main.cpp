/*
Runtime 0 ms Beats 100.00%
Memory 20.58 MB Beats 68.78%
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

    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (i > 0 && j > 0 && matrix[i][j] != matrix[i-1][j-1])
                    return false;
            }
        }
        return true;
    }
};

int main()
{
#if 0
    vector<vector<int>> matrix = {
        {1,2,3,4},{5,1,2,3},{9,5,1,2}
    };
    vector<vector<int>> matrix = {
        {1,2},{2,2}
    };
#endif
    vector<vector<int>> matrix = {
        {1,2},{2,2}
    };
    Solution s;

    for (auto row : matrix)
        s.printVec(row);
    
    bool output = s.isToeplitzMatrix(matrix);
    cout << "Is toeplitz: " << output << endl;
    return 0;
}
