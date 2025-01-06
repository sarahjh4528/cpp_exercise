#include<bits/stdc++.h>
#include<iostream>

using namespace std;

struct TrieNode {
    bool isEnd;
    vector<TrieNode*> children{vector<TrieNode*>(26, nullptr)};
};

class Solution {
    void buildTrie(string& str, TrieNode *root) {
        TrieNode *cur = root;
        for (auto c : str) {
            if (!cur->children[c-'a'])
                cur->children[c-'a'] = new TrieNode();
            cur = cur->children[c-'a'];
        }
        cur->isEnd = true;
    }

    void dfs(TrieNode *cur, string word, vector<string>& res) {
        if (res.size() == 3)
            return;

        if (cur->isEnd)
            res.push_back(word);

        for (int i = 0; i < 26; i++) {
            if (cur->children[i]) {
                word += (i+'a');
                dfs(cur->children[i], word, res);
                word.pop_back();
            }
        }
    }

    vector<string> searchHelper(TrieNode *root, string prefix) {
        TrieNode *cur = root;
        vector<string> res;
        for (auto c : prefix) {
            if (!cur->children[c-'a'])
                return res;
            cur = cur->children[c-'a'];
        }
        dfs(cur, prefix, res);
        return res;
    }

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
/*
Runtime 919 ms Beats 5.51%
Memory 670.97 MB Beats 5.04%

Time : O(M), M: total # of char in products -- buildTrie
       For each prefix, O(len(prefix)), dfs find most 3 words, => O(1)

Space : O(26(n)), n: # of nodes in Trie => O(n)
        O(m), m: len of search word
*/
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode *root = new TrieNode();
        for (auto prod : products)
            buildTrie(prod, root);

        vector<vector<string>> res;
        string prefix = "";
        for (auto c : searchWord) {
            prefix += c;
            res.push_back(searchHelper(root, prefix));
        }
        return res;
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
