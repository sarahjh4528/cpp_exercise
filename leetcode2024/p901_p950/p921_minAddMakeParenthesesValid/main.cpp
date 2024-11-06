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

#if 0
/*
Runtime 0 ms Beats 100.00%
Memory 8.03 MB Beats 10.23%
*/
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
#else
/*
Runtime 0 ms Beats 100.00%
Memory 7.71 MB Beats 73.35%
*/

    int minAddToMakeValid(string s) {
        int open = 0, minmove = 0;
        for (auto c : s) {
            if (c == '(') {
                open++;
            } else if (c == ')' && open > 0) {
                open--;
            } else {
                minmove++;
            }
        }
        return open+minmove;
    }
#endif
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
