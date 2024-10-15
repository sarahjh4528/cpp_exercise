/*
Runtime 49 ms Beats 54.48%
Memory 48.48 MB Beats 66.79%
*/
struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
};

class Trie {
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *cur = root;
        for (auto c : word) {
            int i = c - 'a';
            if (!cur->children[i])
                cur->children[i] = new TrieNode();
            cur = cur->children[i];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode *cur = root;
        for (auto c : word) {
            int i = c - 'a';
            if (!cur->children[i])
                return false;
            cur = cur->children[i];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for (auto c : prefix) {
            int i = c - 'a';
            if (!cur->children[i])
                return false;
            cur = cur->children[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
