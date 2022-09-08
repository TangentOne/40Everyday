/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *findFirstCommonNode(ListNode *headA, ListNode *headB) {
         auto p = headA, q = headB;
        int la = 0, lb = 0;
        for (auto t = headA; t; t = t->next) la ++;
        for (auto t = headB; t; t = t->next) lb ++;
        int k = la - lb;
        if (la < lb) {
            p = headB, q = headA;
            k = lb - la;
        }
        while(k --) {
            p = p->next;
        }
        while(p) {
            if (p == q) return p;
            p = p->next;
            q = q->next;
        }
        return nullptr;
    }


};
