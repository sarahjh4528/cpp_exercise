#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

class Solution {
public:
    void printVec(vector<string> &v) {
        for (auto str : v) {
            cout << str << endl;
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        addingpar(res, "", n, 0);
        return res;
    }
    void addingpar(vector<string> &v, string str, int n, int m){
        if(n==0 && m==0) {
            cout << "push_back : " << str << endl;
            v.push_back(str);
            return;
        }
        cout << "n : " << n << ", m : " << m << ", str : " << str << endl;
        if(m > 0){ addingpar(v, str+")", n, m-1); }
        if(n > 0){ addingpar(v, str+"(", n-1, m+1); }
    }
};

int main()
{
    Solution s;

//    vector<string> output = s.generateParenthesis(2);
    vector<string> output = s.generateParenthesis(3);
//    s.printVec(output);
    return 0;
}
