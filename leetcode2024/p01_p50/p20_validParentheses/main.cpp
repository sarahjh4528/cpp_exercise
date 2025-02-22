/*
Constraints:

1 <= s.length <= 10^4
s consists of parentheses only '()[]{}'.
*/
#include<bits/stdc++.h>
#include<iostream>
#include<stack>

using namespace std;

class Solution {
    unordered_map<char, char> pmap = {
        {'(', ')'},
        {'[', ']'},
        {'{', '}'}
    };
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    bool isValid(string s) {
        stack<char> st;
        for (auto c : s) {
            if (!st.empty() && st.top() == c)
                st.pop();
            else
                st.push(pmap[c]);
        }
        return st.empty();
    }
};

int main()
{
    vector<string> vs = {
        "()",
        "()[]{}",
        "(]",
        "([])"
        
    };
    Solution s;
    for (auto str : vs) {
        cout << str << endl;
        bool output = s.isValid(str);
        cout << "Is valid parentheses: " << output << endl;
    }

    return 0;
}
