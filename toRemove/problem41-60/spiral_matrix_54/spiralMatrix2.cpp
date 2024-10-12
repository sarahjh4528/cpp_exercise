#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void spiralHelper(vector<vector<int>>& matrix, int rowStart, int rowEnd,
                      int colStart, int colEnd, vector<int>& res) {
         if (rowStart > rowEnd || colStart > colEnd)
             return;
         int i = rowStart, j = colStart;
         if (rowStart == rowEnd) {
             while (j <= colEnd)
                 res.push_back(matrix[i][j++]);
             return;
         } else if (colStart == colEnd) {
             while (i <= rowEnd)
                 res.push_back(matrix[i++][j]);
             return;
         }

         while (j < colEnd)
             res.push_back(matrix[i][j++]);
         while (i < rowEnd)
             res.push_back(matrix[i++][j]);
         while (j > colStart)
             res.push_back(matrix[i][j--]);
         while (i > rowStart)
             res.push_back(matrix[i--][j]);
         spiralHelper(matrix, ++rowStart, --rowEnd, ++colStart, --colEnd, res);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return {};

        vector<int> ret;
        spiralHelper(matrix, 0, matrix.size()-1, 0, (matrix[0]).size()-1, ret);
        return ret;
    }
};

int main()
{
#if 0
    vector<vector<int>> inMatrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<vector<int>> inMatrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    vector<vector<int>> inMatrix = {
        {1, 2, 3, 4}
    };
    vector<vector<int>> inMatrix = {
        {1},
        {5},
        {9}
    };
    vector<vector<int>> inMatrix = {
        {1, 2, 3, 4},
        {9, 10, 11, 12}
    };
    vector<vector<int>> inMatrix = {
        {1,2},
        {5,6},
        {9,7}
    };
    vector<vector<int>> inMatrix = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
        {31, 32, 33, 34, 35, 36, 37, 38, 39, 40},
        {41, 42, 43, 44, 45, 46, 47, 48, 49, 50},
        {51, 52, 53, 54, 55, 56, 57, 58, 59, 60},
        {61, 62, 63, 64, 65, 66, 67, 68, 69, 70},
        {71, 72, 73, 74, 75, 76, 77, 78, 79, 80},
        {81, 82, 83, 84, 85, 86, 87, 88, 89, 90},
        {91, 92, 93, 94, 95, 96, 97, 98, 99, 100},
    };
#endif
    vector<vector<int>> inMatrix = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
        {31, 32, 33, 34, 35, 36, 37, 38, 39, 40},
        {41, 42, 43, 44, 45, 46, 47, 48, 49, 50},
        {51, 52, 53, 54, 55, 56, 57, 58, 59, 60},
        {61, 62, 63, 64, 65, 66, 67, 68, 69, 70},
        {71, 72, 73, 74, 75, 76, 77, 78, 79, 80},
        {81, 82, 83, 84, 85, 86, 87, 88, 89, 90},
        {91, 92, 93, 94, 95, 96, 97, 98, 99, 100},
    };
    cout << "Orig matrix: " << endl;
    for (auto v : inMatrix) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    Solution s;
    vector<int> spiralNums = s.spiralOrder(inMatrix);
    cout << spiralNums.size() << endl;
    for (auto i : spiralNums)
        cout << i << " ";
    cout << endl;
    return 0;
}
