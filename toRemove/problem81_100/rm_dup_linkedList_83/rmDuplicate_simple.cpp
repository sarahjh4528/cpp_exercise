#include<iostream>
#include<vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void printList(ListNode *head) {
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

    ListNode* buildList(vector<int> iv) {
        if (iv.empty())
            return NULL;

        ListNode *head = NULL, *cur = NULL;
        head = new ListNode(iv[0]);
        cur = head;
        for (int i = 1; i < iv.size(); ++i) {
            cur->next = new ListNode(iv[i]);
            cur = cur->next;
        }
        return head;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur = head;
        while (cur && cur->next) {
            if (cur->val == cur->next->val)
                cur->next = cur->next->next;
            else
                cur = cur->next;
        }
        return head;
    }
};

int main()
{
#if 0
    vector<int> input = {1,1,2,2,3,4,5,5,6};
    vector<int> input = {1,1,1};
#endif
    vector<int> input = {1,1,1};

    Solution s;
    ListNode *head = s.buildList(input);
    s.printList(head);
    ListNode *deletedHead = s.deleteDuplicates(head);
    s.printList(deletedHead);
    return 0;
}
