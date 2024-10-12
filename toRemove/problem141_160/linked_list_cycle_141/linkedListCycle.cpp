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
    ListNode* buildLinkedList(vector<int> nums) {
        ListNode *head = new ListNode(nums[0]);
        ListNode *cur = head;
        ListNode *retPoint = new ListNode(nums[1]);
        cur->next = retPoint;
        cur = cur->next;
        for (int i = 2; i < nums.size(); ++i) {
            cur->next = new ListNode(i);
            cur = cur->next;
        }
        cur->next = retPoint;
        return head;
    }

    bool hasCycle(ListNode *head) {
        if (!head || !head->next)
            return false;

        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            if (fast == slow || fast->next == slow)
                return true;
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};

int main()
{
    Solution s;
    ListNode *ListHead = s.buildLinkedList({3, 2, 0, -4});

    bool listHasCycle = s.hasCycle(ListHead);
    cout << "List has cycle : " << listHasCycle << endl;
    
    return 0;
}
