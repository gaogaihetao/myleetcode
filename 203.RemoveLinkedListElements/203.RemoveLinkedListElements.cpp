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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* pre = new ListNode(0);
        ListNode* ret = pre;
        pre->next = head;
        while(head != NULL) {
            if(head->val == val) {
                pre->next = head->next;
            } else {
                pre = head;
            }
            head = head->next;
        }
        return ret->next;
    }
};