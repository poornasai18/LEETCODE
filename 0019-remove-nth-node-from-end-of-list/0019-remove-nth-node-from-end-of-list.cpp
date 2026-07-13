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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Create a dummy node before the head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Both pointers start from the dummy node
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast pointer n+1 steps ahead
        // This creates a gap of n nodes between slow and fast
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Node to be deleted
        ListNode* nodeToDelete = slow->next;

        // Remove the node
        slow->next = slow->next->next;

        // Free memory
        delete nodeToDelete;

        // Store new head
        ListNode* newHead = dummy->next;

        // Delete dummy node
        delete dummy;

        return newHead;
    }
};