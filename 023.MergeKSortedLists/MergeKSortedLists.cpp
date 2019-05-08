/******************************************************************************
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 ******************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *mergeKLists(vector<ListNode *> &lists) {
    multimap<int,ListNode *> myMap;
    for(int i=0; i<lists.size(); i++) {
        while(lists[i]) {
            myMap.insert(pair<int, ListNode *>(lists[i]->val,lists[i]));
            lists[i]=lists[i]->next;
        }
    }
    if(myMap.size()==0)
    { return NULL; }
    for(multimap<int,ListNode *>::iterator it=myMap.begin();; it++) {
        multimap<int,ListNode *>::iterator it_next=it;
        it_next++;
        if(it_next==myMap.end()) {
            it->second->next=NULL;
            break;
        }
        it->second->next=it_next->second;
    }
    return myMap.begin()->second;
}