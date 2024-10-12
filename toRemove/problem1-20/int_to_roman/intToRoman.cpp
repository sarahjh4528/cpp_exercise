#include<iostream>
#include<vector>
#include<unordered_map>

using std::endl;
using std::cout;
using std::string;
using std::unordered_map;
using std::vector;

unordered_map<int, string> dict = {
    {1, "I"},
    {4, "IV"},
    {5, "V"},
    {9, "IX"},
    {10, "X"},
    {40, "XL"},
    {50, "L"},
    {90, "XC"},
    {100, "C"},
    {400, "CD"},
    {500, "D"},
    {900, "CM"},
    {1000, "M"}
};

const int factor_seq[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

class Solution {
public:
    string intToRoman(int num) {
        string romanStr = "";
        for (auto i : factor_seq) {
            while (num - i >= 0) {
                romanStr += dict[i];
                num -= i;
            }
        }
        return romanStr;
    }
};

int main()
{
    vector<int> input = {
        3,
        4,
        9,
        58,
        1994,
        3999
    };

    Solution s;
    for (auto i : input) {
        cout << "Input: " << i << endl;
        string romanStr = s.intToRoman(i);
        cout << "Output: " << romanStr << endl;
    }
    return 0;
}
