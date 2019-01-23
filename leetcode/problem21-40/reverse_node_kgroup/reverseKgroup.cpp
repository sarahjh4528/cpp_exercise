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
    void printList(ListNode *nList) {
        while (nList) {
            cout << nList->val << " ";
            nList = nList->next;
        }
        cout << endl;
    }

    ListNode* buildList(vector<int> &iList) {
        ListNode *start = NULL, *cur = NULL;
        for (auto i : iList) {
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

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head)
            return NULL;
        if (k < 2)
            return head;

        ListNode *start = NULL, *segHead = head, *nextElem = NULL, *prev = NULL;
        ListNode *first = NULL, *firstTail = NULL, *second = NULL;

        int i = k;
        bool enoughNode = false;
        while (head) {
            ListNode *nodeCheck = head;
            while(nodeCheck) {
                --i;
                if (i == 0) {
                    enoughNode = true;
                    break;
                }
                nodeCheck = nodeCheck->next;
            }

            if (!enoughNode) {
                if (!prev) {
                    return head;
                } else {
                    prev->next = head;
                    break;
                }
            }

            // There are enough node to swap.
            nextElem = segHead->next;
            for (i = 1; i < k; ++i) {
                if (!firstTail)
                    firstTail = segHead;
                first = segHead;
                second = nextElem;
                firstTail->next = second->next;
                second->next = first;
                segHead = second;
                nextElem = firstTail->next;
            }
            if (!start)
                start = segHead;
            //printList(start);
            if (prev) {
                prev->next = segHead;
            }
            prev = firstTail;
            head = nextElem;
            segHead = head;
            firstTail = NULL;
            enoughNode = false;
        }
        if (!start)
            return head;

        return start;
    }
};

int main() {
#if 0
    vector<int> intList = {1,2,3,4,5,6,7,8,9};
    vector<int> intList = {1};
    vector<int> intList = {};
    vector<int> intList = {1,2};
#endif
    vector<int> intList = {1,2};

    Solution s;
    ListNode *inList = s.buildList(intList);
    s.printList(inList);
#if 0
    ListNode *outList = s.reverseKGroup(inList, 2);
    ListNode *outList = s.reverseKGroup(inList, 3);
    ListNode *outList = s.reverseKGroup(inList, 4);
#endif
    ListNode *outList = s.reverseKGroup(inList, 1);
    s.printList(outList);

    return 0;
}
