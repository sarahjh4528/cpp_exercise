#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* printList(ListNode *head) {
        ListNode *cur = head;
        while (cur) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
    ListNode* buildList(const vector<int> &nList) {
        if (nList.empty())
            return NULL;
        ListNode *head = new ListNode(nList[0]);
        ListNode *cur = head;
        for (int i = 1; i < nList.size(); ++i) {
            cur->next = new ListNode(nList[i]);
            cur = cur->next;
        }
        return head;
    }

    bool isPalindrome(ListNode* head) {
        if (!head)
            return false;
        if (!head->next)
            return true;
        if (!head->next->next) {
            return (head->val == head->next->val)? true : false;
        }
        /* More than 3 elem, push elements onto a stack,
         * Start from beginning, pop element and compare with list val
         */
        stack<int> listStack;
        ListNode *cur = head;
        while (cur) {
            listStack.push(cur->val);
            cur = cur->next;
        }

        while (head) {
            if (head->val == listStack.top()) {
                listStack.pop();
                head = head->next;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<int> nList[] = {
        {},
        {1},
        {1,2},
        {1,2,6,3,4,5,6},
        {1,2,6,3,6,2,1},
    };

    Solution s;
    for (auto nums : nList) {
        ListNode *head = s.buildList(nums);
        s.printList(head);
        bool isPalin = s.isPalindrome(head);
        cout << "Is palindrome: " << isPalin << endl;
    }
    return 0;
}
