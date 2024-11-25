/*
Constraints:

1 <= s1.length, s2.length <= 10^4
s1 and s2 consist of lowercase English letters.
*/
#include<bits/stdc++.h>
#include<iostream>

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
Design : O(26 * n)
*/
    bool checkInclusion(string s1, string s2) {
        vector<int> cmap(26, 0);
        for (auto c : s1)
            cmap[c-'a']++;

        int l1 = s1.length(), l2 = s2.length(), maxi = l2-l1, i = 0;
        while (i <= maxi) {
            int ci = s2[i] - 'a';
            if (cmap[ci] > 0) {
                int j = i;
                vector<int> vmap(cmap.begin(), cmap.end());
                while (j-i < l1 && j < l2) {
                    int vi = s2[j]-'a';
                    vmap[vi]--;
                    if (vmap[vi] < 0)
                        break;
                    j++;
                }
                if (j-i == l1)
                    return true;
            }
            i++;
        }
        return false;
    }
#endif
/*
Design:
Create 2 hash table, based on s1 and s2.
If we find a sequence with s1 permutation, the hash values should satisfy all 26 letters' hash values.
Compare s2's first s1's length string to count matches.

Then use s1 length as sliding window, scan through s2, if we found a substr with 26 matches, return true

Runtime 0 ms Beats 100.00%
Memory 8.82 MB Beats 48.41%

Time: O(s1len)+O(26)+O(s2len-s1len) => O(N), N = s2len
*/
    bool checkInclusion(string s1, string s2) {
        int s1len = s1.length(), s2len = s2.length();
        if (s2len < s1len)  // s2 too short, no possible to find s1 permutation.
            return false;

        vector<int> s1map(26, 0);
        vector<int> s2map(26, 0);
        for (int i = 0; i < s1len; i++) {
            s1map[s1[i]-'a']++;
            s2map[s2[i]-'a']++;
        }
        // Get the 1st sliding window match
        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (s1map[i] == s2map[i])
                matches++;
        }

        for (int i = s1len; i < s2len; i++) {
            if (matches == 26)
                return true;
            int left = s2[i - s1len] - 'a', right = s2[i] - 'a';
            if (left == right)
                continue;
            s2map[left]--;
            s2map[right]++;
            if (s1map[left] == s2map[left])
                matches++;
            else if (s1map[left] == s2map[left]+1)
                matches--;
            if (s1map[right] == s2map[right])
                matches++;
            else if (s1map[right] == s2map[right]-1)
                matches--;
        }
        return (matches == 26)? true : false;
    }
};

int main()
{
    vector<string> vs1 = {
        "ab",
        "ab",
        "adc",
        "abc",
        "trinitrophenylmethylnitramine"
    };
    vector<string> vs2 = {
        "eidbaooo",
        "eidboaoo",
        "dcda",
        "bbbca",
        "dinitrophenylhydrazinetrinitrophenylmethylnitramine"
    };
    Solution s;

    for (int i = 0; i < vs1.size(); i++) {
        cout << "s1 (" << vs1[i] << ")" << endl;
        cout << "s2 (" << vs2[i] << ")" << endl;
        bool output = s.checkInclusion(vs1[i], vs2[i]);
        cout << "Permutation in string: " << output << endl;
    }

    return 0;
}
