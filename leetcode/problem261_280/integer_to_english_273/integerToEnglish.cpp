#include<iostream>
#include<vector>
#include<map>

using namespace std;

map<int, string> digitMap = {
    {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"},
    {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"},
    {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"},
    {15, "Fifteen"}, {16, "Sixteen"}, {17 ,"Seventeen"}, {18 ,"Eighteen"}, {19 ,"Nineteen"},
    {20 ,"Twenty"}, {30 ,"Thirty"}, {40 ,"Forty"}, {50 ,"Fifty"},
    {60 ,"Sixty"}, {70 ,"Seventy"}, {80 ,"Eighty"}, {90 ,"Ninety"},
    {100, "Hundred"},
};
map<int, string> factorMap = {
    {1000, "Thousand"},
    {1000000, "Million"},
    {1000000000, "Billion"},
};

class Solution
{
private:
    string numberToWordsHelper(int num) {
        string res = "";
        map<int, string>::reverse_iterator it = digitMap.rbegin();
        if (num/it->first) {
            res = digitMap[num/it->first] + " " + it->second;
            num %= it->first;
        }
        ++it;
        for (; it != digitMap.rend(); ++it) {
            int curNum = num / it->first;
            if (curNum) {
                res = (res.length() != 0)? res + " " + it->second : it->second;
                num %= it->first;
            }
        }
        return res;
    }
public:
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";

        string res = "";
        map<int, string>::reverse_iterator it = factorMap.rbegin();
        for (; it != factorMap.rend(); ++it) {
            int curStageNum = num / it->first;
            if (curStageNum) {
                string curStageStr = numberToWordsHelper(curStageNum);
                if (res.length() > 0)
                    res += " ";
                res = res + curStageStr + " " + (it->second);
                num %= it->first;
            }
        }

        if (num) {
            string remStr = "";
            remStr = numberToWordsHelper(num);
            if (res.length() > 0)
                res += " ";
            res += remStr;
        }
        return res;
    }
};

int main()
{
    vector<int> inputs = {
        123,
        11000,
        11093,
        12345,
        1234567,
        1234567891
    };

    Solution s;
    for (auto num : inputs) {
        string numStr = s.numberToWords(num);
        cout << "Number: " << num << endl;
        cout << numStr << endl;
    }
    return 0;
}
