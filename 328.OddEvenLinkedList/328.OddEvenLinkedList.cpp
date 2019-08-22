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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddList = new ListNode(0);
        ListNode* evenList = new ListNode(0);
        ListNode* oddListTail = split(head, oddList, evenList);
        oddListTail->next = evenList->next;
        return oddList->next;
    }
    
    ListNode* split(ListNode* head, ListNode* oddList, ListNode* evenList) {
        if(head == NULL) {
            return oddList;
        }
        oddList->next = head;
        if(head->next == NULL) {
            evenList->next = NULL;
            return oddList->next;
        }
        evenList->next = head->next;
        return split(head->next->next, oddList->next, evenList->next);
    }
};