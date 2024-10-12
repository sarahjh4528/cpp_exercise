#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    void printList(ListNode* node) {
        if (!node) {
            return;
        }

        ListNode *cur = node;
        while (cur) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    ListNode* buildList(vector<int>& nums) {
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        for (auto n : nums) {
            ListNode *newListNode = new ListNode(n);
            cur->next = newListNode;
            cur = cur->next;
        }
        return head->next;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = l1->val + l2->val;
        ListNode *sumHead = new ListNode(sum % 10);
        ListNode *cur = sumHead;
        sum /= 10;
        l1 = l1->next;
        l2 = l2->next;
        while (l1 || l2 || sum) {
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            ListNode *newSumNode = new ListNode(sum % 10);
            cur->next = newSumNode;
            cur = cur->next;
            sum /= 10;
        }

        return sumHead;
    }
};

int main() {
    vector<int> in1 = {2, 4, 3};
    vector<int> in2 = {5, 6, 7};

    Solution s;
    ListNode *l1 = s.buildList(in1);
    ListNode *l2 = s.buildList(in2);
    s.printList(l1);
    s.printList(l2);
    ListNode *sum = s.addTwoNumbers(l1, l2);
    s.printList(sum);

    return 0;
}
