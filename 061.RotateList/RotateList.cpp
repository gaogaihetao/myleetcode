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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return NULL;
        deque<ListNode *> que;
        while(head){
            que.push_back(head);
            head=head->next;
        }
        k=k%que.size();
        while(k--){
            cout<<k<<endl;
            ListNode *tmp=que.back();
            tmp->next=que.front();
            que.pop_back();
            que.push_front(tmp);
            que.back()->next=NULL;
        }
        return que.front();
    }
};