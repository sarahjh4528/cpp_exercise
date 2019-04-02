#include<iostream>
#include<vector>

using namespace std;
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
    void printNode(ListNode *list) {
        while(list) {
            cout << list->val << " ";
            list = list->next;
        }
        cout << endl;
    }

    ListNode* buildList(vector<int> &vList) {
        ListNode *start = NULL, *cur = NULL;
        for (auto i : vList) {
            ListNode *newNode = new ListNode(i);
            if (!start) {
                start = newNode;
                cur = newNode;
            } else {
                cur->next = newNode;
                cur = newNode;
            }
        }
        printNode(start);
        return start;
    }

    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(0), *cur = head;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = (l1)? l1 : l2;
        return head->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return {};
        int n = lists.size();
        while (n > 1) {
            int k = (n+1) / 2;
            for (int i = 0; i < n / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[i+k]);
            }
            n = k;
        }
        return lists[0];
    }
};

int main()
{
#if 0
    vector<vector<int>> inputList = {
        {1, 4, 5},
        {1, 3, 4},
        {2, 6}
    };
    vector<vector<int>> inputList = {
        {},
        {1},
        {},
        {2, 6}
    };
    vector<vector<int>> inputList = {
        {},
        {},
    };
    vector<vector<int>> inputList = {
        {},
        {1},
    };
#endif
    vector<vector<int>> inputList = {
        {1, 4, 5},
        {1, 3, 4},
        {2, 6}
    };

    Solution s;
    vector<ListNode*> inputListNode;
    for (auto iList : inputList) {
        ListNode *newList = s.buildList(iList);
        inputListNode.push_back(newList);
    }
    ListNode *output = s.mergeKLists(inputListNode);
    s.printNode(output);
    return 0;
}
