#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void printList(ListNode *start) {
        while (start) {
            cout << start->val << " ";
            start = start->next;
        }
        cout << endl;
    }

    ListNode* buildList(vector<int> &inList) {
        if (inList.empty())
            return NULL;

        ListNode *start = NULL, *cur = NULL;
        for (auto i : inList) {
            if (!start) {
                start = new ListNode(i);
                cur = start;
            } else {
                cur->next = new ListNode(i);
                cur = cur->next;
            }
        }
        return start;

    }

    ListNode* swapPairs(ListNode* head) {
        if (!head)
            return NULL;

        if (head && !head->next) {
            return head;
        }

        ListNode *start = NULL, *prev = NULL, *first = NULL, *second = NULL;
        while (head && head->next) {
            first = head;
            second = head->next;
            if (!start) {
                start = second;
            }
            if (prev)
                prev->next = second;
            first->next = second->next;
            second->next = first;
            prev = first;
            head = head->next;
        }

        return start;

    }
};

int main()
{
#if 0
    vector<int> intList = {1,2,3,4};
    vector<int> intList = {};
    vector<int> intList = {1};
    vector<int> intList = {1,2,3,4,5};
#endif
    vector<int> intList = {1,2,3,4,5,6,7,9};

    Solution s;
    ListNode *inList = s.buildList(intList);
    s.printList(inList);
    ListNode *swappedList = s.swapPairs(inList);
    s.printList(swappedList);

    return 0;
}

