#include<iostream>
#include<string>
#include<vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows < 2)
            return s;

        // vector to hold all the strings in different rows

        vector<string> lines(numRows);
        int rowIndex = 0;
        bool goDown = true;
        for (int i = 0; i < s.length(); ++i) {
            lines[rowIndex] = lines[rowIndex] + s[i];
            if (goDown) {
                // col won't change
                if (rowIndex < numRows - 1) {
                    ++rowIndex;
                } else {
                    goDown = false;
                    --rowIndex;
                }
            } else {
                // move up, both row and col change
                if (rowIndex > 0) {
                    --rowIndex;
                } else {
                    ++rowIndex;
                    goDown = true;
                }
            }
        }
        string outStr = "";
        for (int j = 0; j < numRows; ++j)
            outStr += lines[j];

        return outStr;
    }

#if 0
// Same design, better runtime, 12ms. Above function took 44ms.

string convert(string s, int numRows) {
    if (numRows == 1)return s;
    vector<string> subStr(numRows);
    bool isDescending = false;
    int i = 0;
    for (const auto e : s){
        subStr[i] += e;
        if(i == 0 || i == numRows - 1) isDescending = !isDescending;
        isDescending ? ++i : --i;
    }
    string resStr;
    for (const auto& str : subStr) resStr += str;
    return resStr;
}

#endif
};

int main()
{
    string s = "PAYPALISHIRING";

    Solution sol;

//    string out = sol.convert(s, 3);
    string out = sol.convert(s, 1);
    cout << out << endl;
    
    return 0;
}
