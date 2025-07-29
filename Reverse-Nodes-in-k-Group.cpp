/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ptr = head;
        int count = 0;

        // Step 1: Check if we have at least k nodes to reverse
        while (ptr != nullptr && count < k) {
            ptr = ptr->next;
            count++;
        }

        if (count == k) {
            // Step 2: Reverse k nodes
            ListNode* prev = reverseKGroup(ptr, k); // reverse next group first
            ListNode* curr = head;

            for (int i = 0; i < k; ++i) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            return prev; // new head of this reversed group
        }

        // Step 3: Less than k nodes, return head as-is
        return head;
    }
};
