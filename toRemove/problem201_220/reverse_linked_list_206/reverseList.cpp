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
    ListNode *buildList(const vector<int> &iList) {
        ListNode *head = new ListNode(iList[0]);
        ListNode *cur = head;
        for (int i = 1; i < iList.size(); ++i) {
            cur->next = new ListNode(iList[i]);
            cur = cur->next;
        }
        return head;
    }
 
    void printList(ListNode *head) {
        ListNode *cur = head;
        while (cur) {
            cout << cur->val << " ";
            cur = cur->next; 
        }
        cout << endl;
    }

    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *cur = head, *back = head;
        head = head->next;
        while(head->next) {
            head = head->next;
            if (cur == back) {
                cur = cur->next;
                back->next = NULL;
            }
            cur->next = back;
            back = cur;
            cur = head;
        }
        head->next = back;
        if (cur == back)
            back->next = NULL;
        return head;
    }
};

int main()
{
#if 0
    vector<int> nums = {1,2,3,4,5};
#endif
    vector<int> nums = {1,2};

    Solution s;
    ListNode *listHead = s.buildList(nums);
    s.printList(listHead);
    ListNode *revList = s.reverseList(listHead);
    s.printList(revList);
    return 0;
}
