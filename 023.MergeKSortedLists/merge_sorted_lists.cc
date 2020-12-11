#include <iostream>
#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *Merge(ListNode *l1, ListNode *l2) {
  ListNode* pre = new ListNode(0);
  ListNode *p = pre;
  while (l1 && l2) {
    if (l1->val <= l2->val) {
      p->next = l1;
      l1 = l1->next;
    } else {
      p->next = l2;
      l2 = l2->next;
    }
    p = p->next;
  }
  if (l1) {
    p->next = l1;
  } else {
    p->next = l2;
  }
  return pre->next;
}

ListNode *CreateList(const std::vector<int> &values) {
  if (values.empty()) {
    return nullptr;
  }
  ListNode *head = new ListNode(values[0]);
  ListNode *p = head;
  for (size_t i = 1; i < values.size(); ++i) {
    p->next = new ListNode(values[i]);
    p = p->next;
  }
  return head;
}

void PrintList(ListNode *head) {
  while (head) {
    std::cout << " " << head->val;
    head = head->next;
  }
}

int main()
{
  ListNode *l1 = CreateList({1, 2, 4});
  ListNode *l2 = CreateList({1, 3, 4});
  ListNode *head = Merge(l1, l2);
  std::cout << "result:";
  PrintList(head);
}
