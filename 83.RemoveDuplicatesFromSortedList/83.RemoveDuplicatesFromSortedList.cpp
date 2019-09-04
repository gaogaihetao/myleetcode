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
    ListNode* deleteDuplicates(ListNode* head) {
        deleteNode(head);
        return head;
    }
    
    void deleteNode(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return;
        }
        if(head->val == head->next->val) {
            ListNode* tmp = head->next;
            head->next = head->next->next;
            deleteDuplicates(head);
        } else {
            deleteDuplicates(head->next);
        }
    }
};