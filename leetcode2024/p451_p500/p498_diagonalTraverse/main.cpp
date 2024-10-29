#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
    void traverse(int i, int j, int& direction, vector<vector<int>>& mat, vector<int>& res) {
        int start = res.size();

        while (i < mat.size() && j >= 0)
            res.push_back(mat[i++][j--]);

        if (direction == 0)
            reverse(res.begin()+start, res.end());
        direction ^= 0x1;
    }

public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

/*
Runtime 4 ms Beats 47.31%
Memory 22.16 MB Beats 57.85%
Fastest solution fill output vector bases on direction and i,j position, complicated logic.
*/
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int direction = 1;      // direction: 0-up, 1-down
        int start = 0;          // start index for reverse
        vector<int> res;
        res.push_back(mat[0][0]);
        int rn = mat.size(), cn = mat[0].size();
        for (int col = 1; col < cn; col++) {
            int i = 0, j = col;
            traverse(i, j, direction, mat, res);
        }
        for (int row = 1; row < rn; row++) {
            int i = row, j = cn - 1;
            traverse(i, j, direction, mat, res);
        }

        return res;
    }
};

int main()
{
#if 0
    vector<vector<int>> mat = {
        {1,2,3},{4,5,6},{7,8,9}
    };
#endif
    vector<vector<int>> mat = {
        {1,2,3},{4,5,6},{7,8,9}
    };
    Solution s;

    for (auto row : mat)
        s.printVec(row);
    vector<int> output = s.findDiagonalOrder(mat);
    cout << "Output: " << endl;
    s.printVec(output);
    return 0;
}
