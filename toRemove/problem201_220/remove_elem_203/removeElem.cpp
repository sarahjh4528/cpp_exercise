#include<iostream>
#include<vector>

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
        ListNode *head = new ListNode(nList[0]);
        ListNode *cur = head;
        for (int i = 1; i < nList.size(); ++i) {
            cur->next = new ListNode(nList[i]);
            cur = cur->next;
        }
        return head;
    }

    ListNode* removeElements(ListNode* head, int val) {
        if (!head)
            return NULL;

        ListNode *newHead = NULL, *cur = NULL;
        while (head) {
            if (head->val != val) {
                if (!newHead) {
                    newHead = head;
                    cur = newHead;
                } else {
                    cur->next = head;
                    cur = cur->next;
                }
            }
            head = head->next;
        }
        if (cur)
            cur->next = head;
        return newHead;
    }
};

int main()
{
    vector<int> nList = {1,2,6,3,4,5,6};
    int n = 6;

    Solution s;
    ListNode *head = s.buildList(nList);
    s.printList(head);
    ListNode *remList = s.removeElements(head, n);
    s.printList(remList);
    return 0;
}
