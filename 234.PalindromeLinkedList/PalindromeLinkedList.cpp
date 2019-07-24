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
    bool isPalindrome(ListNode* head) {
        /* O(n) time O(n) space
        vector<int> vec;
        while(head) {
            vec.push_back(head->val);
            head = head->next;
        }
        for(int i = 0; i < vec.size()/2; i++) {
            if(vec[i] != vec[vec.size() - i - 1])
                return false;
        }
        return true;
        */
        
        // O(n) time O(1) space
        ListNode* mid = findMid(head);
        //ListNode* head2 = reverse(mid);
        ListNode* head2 = reverseInIterative(mid);
        while(head2) {
            if(head->val != head2->val)
                return false;
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }
    
    ListNode* findMid(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast) {
            fast = fast->next;
            slow = slow->next;
            if(fast == NULL)
                break;
            fast = fast->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* cur) {
        if(cur == NULL || cur->next == NULL)
            return cur;
        ListNode* tail = reverse(cur->next);
        cur->next->next = cur;
        cur->next = NULL;
        return tail;
    }
    
    ListNode* reverseInIterative(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* pre = NULL;
        while(head) {
            ListNode* cur = head;
            head = head->next;
            cur->next = pre;
            pre = cur;
        }
        return pre;
    }
};