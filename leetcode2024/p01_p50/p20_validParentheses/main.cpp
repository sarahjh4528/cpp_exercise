/*
Runtime 0 ms Beats 100.00%
Memory 9.30 MB Beats 5.46%
*/
class Solution {
    unordered_map<char, char> cmap = {
        {'(', ')'},
        {'[', ']'},
        {'{', '}'}
    };
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto c : s) {
            if (!st.empty() && cmap[st.top()] == c) {
                st.pop();
                continue;
            }
            st.push(c);
        }
        return st.empty();
    }
};
