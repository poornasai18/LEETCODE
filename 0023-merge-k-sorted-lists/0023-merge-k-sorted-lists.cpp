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

    // Comparator for the priority queue.
    // It creates a Min Heap based on node values.
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Min Heap to always get the smallest node.
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        // Insert the first node of every non-empty list.
        for (ListNode* head : lists) {
            if (head != nullptr)
                pq.push(head);
        }

        // Dummy node simplifies list construction.
        ListNode dummy;

        // Tail points to the last node
        // in the merged linked list.
        ListNode* tail = &dummy;

        // Continue until the heap becomes empty.
        while (!pq.empty()) {

            // Get the smallest node.
            ListNode* smallest = pq.top();
            pq.pop();

            // Attach it to the merged list.
            tail->next = smallest;
            tail = tail->next;

            // If the extracted node has a next node,
            // insert it into the heap.
            if (smallest->next != nullptr) {
                pq.push(smallest->next);
            }
        }

        // Return the merged list.
        return dummy.next;
    }
};