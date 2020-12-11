**Merge Two Sorted Lists**

- Merge two sorted linked lists and return it as a new sorted list.

- The new list should be made by splicing together the nodes of the first two lists.

**合并两个有序链表**

- 将两个升序链表合并为一个新的升序链表并返回。
- 新链表是通过拼接给定的两个链表的所有节点组成的。

**input:**

list 1: 1->2->4
list 2: 1->3->4

**output:**

1->1->2->3->4->4

**函数签名：**

```c++
ListNode* merge(ListNode* l1, ListNode* l2);
```

**结构体定义：**

```c++
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};
```

**创建链表的函数：**

```c++
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
```

**打印链表的函数：**

```c++
void PrintList(ListNode *head) {
  while (head) {
    std::cout << " " << head->val;
    head = head->next;
  }
}
```

**main函数：**

```c++
#include <iostream>
#include <vector>

int main()
{
  ListNode *l1 = CreateList({1, 2, 4});
  ListNode *l2 = CreateList({1, 3, 4});
  ListNode *head = Merge(l1, l2);
  std::cout << "result:";
  PrintList(head);
}
```

**迭代实现：**

```c++
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
```