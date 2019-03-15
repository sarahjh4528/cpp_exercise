#include<iostream>
#include<vector>

using namespace std;

#define SUDO_ROW 9
#define SUDO_COL 9

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<short> row(9, 0);    // Each one represents one row, check bit of each
        vector<short> col(9, 0);
        vector<short> block(9, 0);

        for (int rw = 0; rw < SUDO_ROW; ++rw) {
            for (int cl = 0; cl < SUDO_COL; ++cl) {
                if (board[rw][cl] != '.') {
                    int bitLoc = (1 << board[rw][cl] - '0');    // shift bit by char value
                    int bIndex = (rw / 3) * 3 + cl / 3;         // Row quotient * rows + col quotient
                    // cout << "rw: " << rw << ", cl: " << cl << ", bIndex: " << bIndex << endl;
                    if ((row[rw] & bitLoc) || (col[cl] & bitLoc) ||
                        (block[bIndex] & bitLoc))
                        return false;
                    row[rw] |= bitLoc;
                    col[cl] |= bitLoc;
                    block[bIndex] |= bitLoc;
                }   
            }
        }
        return true;
    }
};
int main()
{
#if 0
    vector<vector<char>> sudoB = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'},
    };

    vector<vector<char>> sudoB = {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'},
    };
#endif
    vector<vector<char>> sudoB = {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'},
    };
    Solution s;
    bool isValid = s.isValidSudoku(sudoB);
    cout << "The board is valid: " << isValid << endl;
    return 0;
}
