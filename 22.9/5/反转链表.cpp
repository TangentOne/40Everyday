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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        ListNode*potherhead=NULL ;
        ListNode*pend=head;
        while(pend!=NULL)
        {
         ListNode*ptemp=pend->next;
         pend->next=potherhead;
         potherhead=pend;
         pend=ptemp;
            
        }
        return potherhead;
        
    }
};
