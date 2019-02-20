#include<iostream>
#include<unordered_map>

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
    void printList(ListNode *l) {
        while (l) {
            cout << l->val << " ";
            l = l->next;
        }
        cout << endl;
    }
#if 0
[1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35,37,39,41,42]
    
[2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,41,42]
#endif

    void buildLists(ListNode **l1Head, ListNode **l2Head) {
        *l1Head = new ListNode(4);
        *l2Head = new ListNode(5);
        ListNode *cur1 = *l1Head, *cur2 = *l2Head;
        cur1->next = new ListNode(1);
        cur2->next = new ListNode(0);
        cur1 = cur1->next;
        cur2 = cur2->next;
#if 0
        cur1->next = new ListNode(15);
        cur1 = cur1->next;
#endif
        cur2->next = new ListNode(1);
        cur2 = cur2->next;
        ListNode *interNode = new ListNode(8);
        cur1->next = interNode;
        cur2->next = interNode;
        cur1 = cur1->next;
        cur1->next = new ListNode(4);
        cur1 = cur1->next;
        cur1->next = new ListNode(5);

    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA && !headB)
            return NULL;
        if (headA == headB)
            return headA;
        ListNode *ap = headA, *bp = headB;

        while (ap && bp && ap != bp) {
            ap = ap->next;
            bp = bp->next;

            if (ap == bp)
                return ap;
            if (!ap) ap = headB;
            if (!bp) bp = headA;
        }
        return ap;
    }
};

int main()
{
    Solution s;
    ListNode *l1 = NULL, *l2 = NULL;
    s.buildLists(&l1, &l2);
//    s.printList(l1);

    ListNode *intersectNode = s.getIntersectionNode(l1, l2);
    if (intersectNode)
        cout << intersectNode->val << endl;
    else
        cout << "No intersection" << endl;

    return 0;
}
