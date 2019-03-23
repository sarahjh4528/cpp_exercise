#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty() && grid[0].empty())
            return 0;
        int perimeter = 0;
        int rLen = grid.size(), cLen = grid[0].size();
        for (int i = 0; i < rLen; ++i) {
            for (int j = 0; j < cLen; ++j) {
                if (grid[i][j] == 1) {
                    perimeter += 4;
                    if (i > 0 && grid[i-1][j] == 1)
                        --perimeter;
                    if (j > 0 && grid[i][j-1] == 1)
                        --perimeter;
                    if (i + 1 < rLen && grid[i+1][j] == 1)
                        --perimeter;
                    if (j + 1 < cLen && grid[i][j+1] == 1)
                        --perimeter;
                }
            }
        }
        return perimeter;
    }
};
int main()
{
    vector<vector<int>> islandMap = {
        {0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0},
    };
    Solution s;
    int perimeter = s.islandPerimeter(islandMap);
    cout << "Perimeter: " << perimeter << endl;
    return 0;
}
