/*
Runtime 29 ms Beats 13.58%
Memory 24.31 MB Beats 39.30%

Same implementation as fastest solution
*/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class TicTacToe {
    vector<int> vr;    // Each field represent entire row accumulated result
    vector<int> vc;
    int diagonal, rdiagonal, bn;
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    TicTacToe(int n) {
        bn = n;
        vr.resize(n);
        vc.resize(n);
        diagonal = 0;
        rdiagonal = 0;
    }
    
    int move(int row, int col, int player) {
        int m = (player == 1)? 1 : -1;
        vr[row] += m;
        vc[col] += m;
        if (row == col)
            diagonal += m;
        if (row == bn - 1 - col)
            rdiagonal += m;

        if ((abs(vr[row]) == bn) ||
            (abs(vc[col]) == bn) ||
            (abs(diagonal) == bn) ||
            (abs(rdiagonal) == bn))
            return player;

        return 0;
    }
};

int main()
{
/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
    vector<vector<int>> moves = {
        {0, 0, 1}, {0, 2, 2}, {2, 2, 1}, {1, 1, 2}, {2, 0, 1}, {1, 0, 2}, {2, 1, 1}
    };
    
    TicTacToe obj(3);
    for (auto move : moves) {
        obj.printVec(move);
        int output = obj.move(move[0],move[1],move[2]);
        if (output)
            cout << "Player " << move[2] << " won." << endl;
            
    }

    return 0;
}
