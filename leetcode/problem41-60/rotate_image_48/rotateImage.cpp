#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    void printImage(vector<vector<int>>& matrix) {
        for (auto v : matrix) {
            for (auto i : v)
                cout << i << " ";
            cout << endl;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix.size() == 1)
            return;
        int n = matrix.size() - 1;
        for (int i = 0; i <= n; ++i) {
            for (int j = i; j <= n - i - 1; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-j][i];
                matrix[n-j][i] = matrix[n-i][n-j];
                matrix[n-i][n-j] = matrix[j][n-i];
                matrix[j][n-i] = temp;
            }
        }
    }
};

int main()
{
#if 0
    vector<vector<int>> image = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    vector<vector<int>> image = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    vector<vector<int>> image = {
        {1,2,3,4,0},
        {5,6,7,8,0},
        {9,10,11,12,12},
        {13,14,15,16,16},
        {17,18,19,20,21}
    };
    vector<vector<int>> image = {};
    vector<vector<int>> image = {{1}};
#endif
    vector<vector<int>> image = {{1}};

    Solution s;
    cout << "Orig image: " << endl;
    s.printImage(image);
    s.rotate(image);
    cout << "Rotated image: " << endl;
    s.printImage(image);
    return 0;
}
