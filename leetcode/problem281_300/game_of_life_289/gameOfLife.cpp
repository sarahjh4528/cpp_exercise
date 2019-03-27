#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    void printVec(const vector<vector<int>>& board) {
        for (auto v : board) {
            for (auto i : v)
                cout << i << " ";
            cout << endl;
        }
    }

    void gameLifeHelper(const vector<vector<int>>& board, int row, int col, vector<vector<bool>>& map) {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                int liveNeighbors = 0;
                if (i-1 >= 0) {
                    liveNeighbors = (j-1>=0 && board[i-1][j-1] == 1)? ++liveNeighbors : liveNeighbors;
                    liveNeighbors = (board[i-1][j] == 1)? ++liveNeighbors : liveNeighbors;
                    liveNeighbors = (j+1<col && board[i-1][j+1] == 1)? ++liveNeighbors : liveNeighbors;
                }
                liveNeighbors = (j-1>=0 && board[i][j-1] == 1)? ++liveNeighbors : liveNeighbors;
                liveNeighbors = (j+1<col && board[i][j+1] == 1)? ++liveNeighbors : liveNeighbors;
                if (i+1 < row) {
                    liveNeighbors = (j-1>=0 && board[i+1][j-1] == 1)? ++liveNeighbors : liveNeighbors;
                    liveNeighbors = (board[i+1][j] == 1)? ++liveNeighbors : liveNeighbors;
                    liveNeighbors = (j+1<col && board[i+1][j+1] == 1)? ++liveNeighbors : liveNeighbors;
                }
                if (liveNeighbors < 2 && board[i][j] == 1
                    || liveNeighbors > 3 && board[i][j] == 1
                    || liveNeighbors == 3 && board[i][j] == 0)
                    map[i][j] = true;    // flip 
            }
        }
    }
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty())
            return;

        int row = board.size(), col = board[0].size();
        vector<vector<bool>> flipMap(row, vector<bool>(col, false));
        gameLifeHelper(board, row, col, flipMap);

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (flipMap[i][j]) {
                    board[i][j] ^= 0x1;
                    cout << i << ", " << j << ": " << board[i][j] << endl;
                }
            }
        }
    }
};

int main()
{
    vector<vector<int>> board = {
        {0,1,0},
        {0,0,1},
        {1,1,1},
        {0,0,0}
    };

    Solution s;
    s.printVec(board);
    s.gameOfLife(board);
    cout << "Result: " << endl;
    s.printVec(board);

    return 0;
}
