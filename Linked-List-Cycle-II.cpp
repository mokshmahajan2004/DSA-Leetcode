/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //Slow Fast pointer (Tortoise Method)
 //TC->O(n)
 //SC->O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
     ListNode* slow=head;
     ListNode* fast=head;
     ListNode* dum=head;
     if(head==NULL||head->next==NULL) return NULL;
     while(fast->next&&fast->next->next)  {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            while(slow!=dum){
                slow=slow->next;
                dum=dum->next;
            }
            return slow;
        }
     }
     return NULL; 
    }
};