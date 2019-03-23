#include<iostream>

using namespace std;

class Solution
{
public:
    bool judgeCircle(string moves) {
        int row = 0, col = 0;
        for (int i = 0; i < moves.length(); ++i) {
            switch (moves[i]) {
                case 'R':
                    ++row;
                    break;
                case 'L':
                    --row;
                    break;
                case 'U':
                    ++col;
                    break;
                case 'D':
                    --col;
                    break;
                default:
                    break;
            }
        }
        return (row == 0 && col == 0)? true : false;
    }
};
int main()
{
#if 0
    string moves = "UD";
    string moves = "LL";
#endif
    string moves = "LL";
    Solution s;
    bool rReturn = s.judgeCircle(moves);
    cout << "Robot return : " << rReturn << endl;
    return 0;
}
