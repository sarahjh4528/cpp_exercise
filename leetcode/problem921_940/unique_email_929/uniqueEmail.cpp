#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution
{
public:
    int numUniqueEmails(vector<string>& emails) {
        int count = 0;
        unordered_set<string> eSet;
        for (auto email : emails) {
            string validEmail = "";
            int curLen = email.length();
            int i = 0;
            while (email[i] != '@') {
                if (email[i] == '.') {
                    ++i;
                    continue;
                } else if (email[i] == '+') {
                    while (email[i] != '@')
                        ++i;
                    break;
                } else {
                    validEmail.push_back(email[i]);
                }
                ++i;
            }
            validEmail += email.substr(i);
//            cout << validEmail << endl;
            eSet.insert(validEmail);
        }
        return eSet.size();
    }
};
int main()
{
#if 0
    vector<string> emails = {
        "test.email+alex@leetcode.com",
        "test.e.mail+bob.cathy@leetcode.com",
        "testemail+david@lee.tcode.com"
    };
#else
    vector<string> emails = {
        "testemail@leetcode.com",
        "testemail1@leetcode.com",
        "testemail+david@lee.tcode.com"
    };
#endif

    Solution s;
    int uniqueCount = s.numUniqueEmails(emails);
    cout << "Number of unique emails: " << uniqueCount << endl;

    return 0;
}
