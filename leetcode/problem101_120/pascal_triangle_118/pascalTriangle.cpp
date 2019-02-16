#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    void printTriangle(vector<vector<int>>& tri) {
        for (auto level : tri) {
            for (auto i : level)
                cout << i << " ";
            cout << endl;
        }
        cout << endl;
    }

    vector<vector<int>> generate(int numRows) {
        if (numRows == 0)
            return {};
            
        vector<vector<int>> triangle(numRows, vector<int> {1});
        if (numRows == 1)
            return triangle;

        triangle[1].push_back(1);
        if (numRows == 2)
            return triangle;

        for (int i = 2; i < numRows; ++i) {
            for (int j = 1; j < i; ++j) {
                triangle[i].push_back(triangle[i-1][j] + triangle[i-1][j-1]);
            }
            triangle[i].push_back(1);
        }
        return triangle;
    }
};
int main()
{
    int rows = 5;

    Solution s;
    vector<vector<int>> triangle = s.generate(rows);
    s.printTriangle(triangle);
    return 0;
}
