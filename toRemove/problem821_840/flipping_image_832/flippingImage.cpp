#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        if (A.empty() && A[0].empty())
            return {};

        int rows = A.size(), cols = A[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols / 2; ++j) {
                int temp = A[i][j];
                A[i][j] = (A[i][cols-1-j] ^ 0x1);
                A[i][cols-1-j] = (temp ^ 0x1);
            }
        }
        if (cols % 2) {
            int colLeft = cols/2;
            for (int k = 0; k < rows; ++k)
                A[k][colLeft] ^= 0x1;
        }
        return A;
    }
};
int main()
{
    vector<vector<int>> image = {
        {1,1,0},
        {1,0,1},
        {0,0,0},
    };
    Solution s;
    vector<vector<int>> flippedImage = s.flipAndInvertImage(image);
    for (auto v : flippedImage) {
        for (auto p : v)
            cout << p << " ";
        cout << endl;
    }
    return 0;
}
