/*
 * A strobogrammatic number is a number that looks the same when rotated 180 degrees
 * (looked at upside down).
 * 
 * Write a function to determine if a number is strobogrammatic. The number is
 * represented as a string.
 * 
 * Example 1:
 * Input:  "69"
 * Output: true
 * 
 * Example 2:
 * Input:  "88"
 * Output: true
 * 
 * Example 3:
 * Input:  "962"
 * Output: false
 */
#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

unordered_map<char, char> nMap = {
    {'6', '9'},
    {'9', '6'},
    {'0', '0'},
    {'1', '1'},
    {'8', '8'}
};

class Solution {
public:
    bool isStrobogrammatic(string num) {
        int len = num.size();
        if (len == 0)
            return false;

        bool isOdd = (len % 2)? true : false;
        int b = (isOdd)? (len-1)/2 - 1 : (len-1)/2;
        int f = (isOdd)? (len-1)/2 + 1 : len/2;
        if (isOdd) {
            int mid = (len-1) / 2;
            if (num[mid] != '0' && num[mid] != '1' && num[mid] != '8')
                return false;
        }
        while (b >= 0 && f <= len - 1) {
            if (nMap[num[b--]] == num[f++])
                continue;
            return false;
        }
        return true;
    }
};

int main()
{
    vector<string> inputs = {
        "69",
        "88",
        "962",
        "0110",
        "10101",
        "818",
        "681808189",
        "681868189",
    };

    Solution s;
    for (auto input : inputs) {
        bool isStrobo = s.isStrobogrammatic(input);
        cout << input << " is strobogrammatic: " << isStrobo << endl;
    }
    return 0;
}
