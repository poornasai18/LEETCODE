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
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* head1 = nullptr;
        ListNode* temp = head;
        ListNode* temp1 = head1;
        while(temp) {
            int cnt = 1;
            if(temp->next == nullptr) {
                if(head1 == nullptr) {
                    head1 = new ListNode(temp->val);
                    temp1 = head1;
                    cout << temp->val << " " << temp1->val << endl;
                }else{
                    temp1->next = new ListNode(temp->val);
                    temp1 = temp1->next;
                    cout << temp->val << " " << temp1->val << endl;
                }
            }else{
            while(temp->next != nullptr && temp->next->val == temp->val) {
                temp = temp->next;
                cnt++;
            }
            if(cnt == 1) {
                if(head1 == nullptr) {
                    head1 = new ListNode(temp->val);
                    temp1 = head1;
                    cout << temp->val << " " << temp1->val << endl;
                }else{
                    temp1->next = new ListNode(temp->val);
                    temp1 = temp1->next;
                    cout << temp->val << " " << temp1->val << endl;
                }
            }
        }
            temp = temp->next;
        }
        return head1;
    }
};