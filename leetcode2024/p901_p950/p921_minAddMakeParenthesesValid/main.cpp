/*
Runtime 0 ms Beats 100.00%
Memory 8.03 MB Beats 10.23%
*/
#include<bits/stdc++.h>
#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    int minAddToMakeValid(string s) {
        stack<char> st;
        for (auto c : s) {
            if (!st.empty() && c == ')' && st.top() == '(') {
                st.pop();
                continue;
            }
            st.push(c);
        }
        return st.size();
    }

};

int main()
{
    vector<string> input = { "())", "(((" };
    Solution s;

    for (auto str : input) {
        cout << str << endl;
        int output = s.minAddToMakeValid(str);
        cout << "Min number of move to make it valid : " << output << endl;
    }
    return 0;
}
