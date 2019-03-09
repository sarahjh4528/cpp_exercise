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
};

int main()
{
    vector<int> nList = {1,2,6,3,4,5,6};

    Solution s;
    ListNode *head = s.buildList(nList);
    s.printList(head);
    return 0;
}
