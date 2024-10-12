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
    void printList(ListNode *list) {
        if (!list)
            return;

        while (list) {
            cout << list->val << " ";
            list = list->next;
        }
        cout << endl;
    }

    ListNode *buildList(vector<int> &v) {
        ListNode *start = NULL, *end = NULL;
        for (auto i : v) {
            ListNode *newNode = new ListNode(i);
            if (!start) {
                start = newNode;
                end = newNode;
            } else {
                end->next = newNode;
                end = newNode;
            }
        }
        return start;
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *mergedStart = NULL, *mergedPtr = NULL;

        if (!l1 || !l2) {
            mergedStart = (l1)? l1 : l2;
            return mergedStart;
        }

        if (l1->val < l2->val) {
            mergedStart = l1;
            mergedPtr = l1;
            l1 = l1 -> next;
        } else {
            mergedStart = l2;
            mergedPtr = l2;
            l2 = l2 -> next;
        }

        while (l1 && l2) {
            if (l1->val < l2->val) {
                mergedPtr->next = l1;
                mergedPtr = mergedPtr->next;
                l1 = l1->next;
            } else {
                mergedPtr->next = l2;
                mergedPtr = mergedPtr->next;
                l2 = l2->next;
            }
        }
        if (l1)
            mergedPtr->next = l1;
        if (l2)
            mergedPtr->next = l2;

        return mergedStart;

    }
};
int main()
{
    vector<int> input1 = {1,2,4};
    vector<int> input2 = {1,1,2,2,3,4,5,6,7};
//    vector<int> input2 = {};

    Solution s;
    ListNode *list1 = s.buildList(input1);
    ListNode *list2 = s.buildList(input2);
    s.printList(list1);
    s.printList(list2);


    ListNode *mergedList = s.mergeTwoLists(list1, list2);
    s.printList(mergedList);

    return 0;
}
