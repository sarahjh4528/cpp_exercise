#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {

public:
    void printVec(vector<string>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

/*
1 <= products.length <= 1000
1 <= products[i].length <= 3000
1 <= sum(products[i].length) <= 2 * 10^4
All the strings of products are unique.
products[i] consists of lowercase English letters.
1 <= searchWord.length <= 1000
searchWord consists of lowercase English letters.
*/
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    }

};

int main()
{
    vector<vector<string>> vprod = {
        {"mobile","mouse","moneypot","monitor","mousepad"},
        {"havana"}
    };
    vector<string> vsw = {"mouse", "havana"};
    Solution s;
    for (int i = 0; i < vprod.size(); i++) {
        s.printVec(vprod[i]);
        vector<vector<string>> output = s.suggestedProducts(vprod[i], vsw[i]);
        for (auto strs : output)
            s.printVec(strs);
    }

    return 0;
}
