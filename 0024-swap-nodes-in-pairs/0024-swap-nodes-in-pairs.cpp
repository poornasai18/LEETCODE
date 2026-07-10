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
    ListNode* swapPairs(ListNode* head) {

        // Create a dummy node before the head.
        // This makes swapping the first pair easier.
        ListNode dummy(0);
        dummy.next = head;

        // 'prev' always points to the node
        // just before the current pair.
        ListNode* prev = &dummy;

        // Continue while there are at least
        // two nodes available for swapping.
        while (prev->next != nullptr && prev->next->next != nullptr) {

            // First node of the pair.
            ListNode* first = prev->next;

            // Second node of the pair.
            ListNode* second = first->next;

            // ---------- Swap the two nodes ----------

            // First now points to the node
            // after the second node.
            first->next = second->next;

            // Second points to the first node.
            second->next = first;

            // Previous node now points to second,
            // making second the new first node.
            prev->next = second;

            // ----------------------------------------

            // Move 'prev' to the end of the swapped pair
            // to process the next pair.
            prev = first;
        }

        // Return the new head of the list.
        return dummy.next;
    }
};