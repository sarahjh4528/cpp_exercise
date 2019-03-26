#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    bool bstSearch(vector<vector<int>>& matrix, int row, int col, int target) {
        if (row < 0 || col >= matrix[0].size())
            return false;
        if (matrix[row][col] == target)
            return true;
        if (matrix[row][col] > target)
            return bstSearch(matrix, row-1, col, target);
        else
            return bstSearch(matrix, row, col+1, target);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;

        // BST search , treat left bottom node as root.
        return bstSearch(matrix, matrix.size() - 1, 0, target);
    }
#if 0
// Faster and simpler solution
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        int row = 0, col = matrix[0].size() - 1;
        while(row < matrix.size() && col >= 0) {
            if(matrix[row][col] > target) --col;
            else if(matrix[row][col] < target) ++row;
            else return true;
        }
        return false;
    }

#endif
};

int main()
{
#if 0
    int target = 5;
    int target = 20;
    vector<vector<int>> matrix = {
        { 1,   4,  7, 11, 15},
        { 2,   5,  8, 12, 19},
        { 3,   6,  9, 16, 22},
        { 10, 13, 14, 17, 24},
        { 18, 21, 23, 26, 30}
    };

    int target = 19;
    vector<vector<int>> matrix = {
        { 1,  2,  3,  4,  5},
        { 6,  7,  8,  9, 10},
        { 11, 12, 13, 14, 15},
        { 16, 17, 18, 19, 20},
        { 21, 22, 23, 24, 25}
    };
#endif
    int target = 0;
    vector<vector<int>> matrix = {
        {-1},
        {-1},
    };

    Solution s;
    bool foundTarget = s.searchMatrix(matrix, target);
    cout << "Target found: " << foundTarget << endl;
    return 0;
}
