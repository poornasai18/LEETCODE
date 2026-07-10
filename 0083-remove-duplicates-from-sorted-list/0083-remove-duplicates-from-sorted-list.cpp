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
    ListNode* deleteDuplicates(ListNode* head) {

        // If the list is empty or has only one node,
        // there can't be any duplicates.
        if (head == nullptr || head->next == nullptr)
            return head;

        // Start traversing from the head node.
        ListNode* current = head;

        // Continue until the current node or the next node becomes NULL.
        while (current != nullptr && current->next != nullptr) {

            // If the current node and the next node
            // have the same value, remove the duplicate node.
            if (current->val == current->next->val) {

                // Store the duplicate node temporarily.
                ListNode* duplicate = current->next;

                // Skip the duplicate node.
                current->next = current->next->next;

                // Free the memory occupied by the duplicate node.
                delete duplicate;
            }
            else {

                // If values are different,
                // move to the next node.
                current = current->next;
            }
        }

        // Return the head of the updated linked list.
        return head;
    }
};