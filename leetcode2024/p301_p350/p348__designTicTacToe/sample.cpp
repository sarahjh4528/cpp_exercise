#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class TicTacToe {
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    TicTacToe(int n) {
    }
    
    int move(int row, int col, int player) {
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
