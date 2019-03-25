#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    void dfsTraverse(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = 'm';    // Mark

        // Up
        if (i > 0 && grid[i-1][j] == '1')
            dfsTraverse(grid, i-1, j);

        // Down
        if (i + 1 < grid.size() && grid[i+1][j] == '1')
            dfsTraverse(grid, i+1, j);

        // Left
        if (j > 0 && grid[i][j-1] == '1')
            dfsTraverse(grid, i, j-1);

        // Right
        if (j + 1 < grid[0].size() && grid[i][j+1] == '1')
            dfsTraverse(grid, i, j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;

        int rows = grid.size(), cols = grid[0].size();
        int islandCount = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    ++islandCount;
                    dfsTraverse(grid, i, j);
                }
            }
        }
        return islandCount;
    }
};
int main()
{
#if 0
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'},
    };
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'},
    };
    vector<vector<char>> grid = {};
    vector<vector<char>> grid = {
        {'1','1','1'},
        {'0','1','0'},
        {'1','1','1'},
    };
    vector<vector<char>> grid = {
        {'1','1','1','1','1','1','1'},
        {'0','0','0','0','0','0','1'},
        {'1','1','1','1','1','0','1'},
        {'1','0','0','0','1','0','1'},
        {'1','0','1','0','1','0','1'},
        {'1','0','1','1','1','0','1'},
        {'1','1','1','1','1','1','1'},
    };
#endif
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'},
    };
    Solution s;
    int islandNum = s.numIslands(grid);
    cout << "Number of islands: " << islandNum << endl;
    return 0;
}
