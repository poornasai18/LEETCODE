/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;              // Value stored in the node
 *     ListNode *next;       // Pointer to the next node
 *
 *     // Constructor
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // Create a dummy node.
        // It simplifies the logic because we don't have to handle
        // the first node of the merged list separately.
        ListNode dummy;

        // 'tail' always points to the last node
        // of the merged linked list.
        ListNode* tail = &dummy;

        // Continue until one of the lists becomes empty.
        while (list1 != nullptr && list2 != nullptr) {

            // Compare the current nodes of both lists.
            if (list1->val <= list2->val) {

                // Attach the smaller node to the merged list.
                tail->next = list1;

                // Move list1 to its next node.
                list1 = list1->next;
            }
            else {

                // Attach the smaller node from list2.
                tail->next = list2;

                // Move list2 to its next node.
                list2 = list2->next;
            }

            // Move the tail pointer forward.
            tail = tail->next;
        }

        // At this point, one of the lists is empty.

        // If list1 still has nodes, attach them.
        if (list1 != nullptr)
            tail->next = list1;

        // Otherwise attach remaining nodes of list2.
        else
            tail->next = list2;

        // The merged list starts after the dummy node.
        return dummy.next;
    }
};