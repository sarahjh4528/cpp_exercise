#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

class Solution
{
public:
    void printList(vector<int>& nums) {
        for (auto i : nums) {
            cout << i << " ";
        }
        cout << endl;
    }

    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int dLen = digits.size();
        if (digits[dLen - 1] + 1 < 10) {
            digits[dLen - 1] += 1;
            return digits;
        } else {
            carry = 1;
            digits[dLen - 1] = 0;
            for (int i = dLen - 2; i >= 0; --i) {
                if (digits[i] + carry == 10) {
                    digits[i] = 0;
                } else {
                    digits[i] += 1;
                    return digits;
                }
            }
            if (carry)
                digits.insert(digits.begin(), 1);
            return digits;
        }
    }
};

int main()
{
#if 0
    vector<int> iList = {1,2,3};
    vector<int> iList = {9, 9};
    vector<int> iList = {0};
    vector<int> iList = {4,3,2,1};
#endif
    vector<int> iList = {4,3,2,1};

    Solution s;
    s.printList(iList);
    vector<int> oList = s.plusOne(iList);
    s.printList(oList);
    return 0;
}
