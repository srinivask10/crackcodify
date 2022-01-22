using namespace std;
 
#include <iostream>
#include <queue>
#include <vector>
 
class ListNode {
 public:
  int value = 0;
  ListNode *next;
 
  ListNode(int value) {
    this->value = value;
    this->next = nullptr;
  }
};
 
class MergeKSortedLists {
 public:

  struct ValCompare
  {
      bool operator ()(const ListNode *n1, const ListNode *n2) { return (n1->value > n2->value); }
  };

  static ListNode *merge(const vector<ListNode *> &lists) {
    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    priority_queue<ListNode*, vector<ListNode*>, ValCompare> minheap;

    for (ListNode *node : lists)
        if (node)
            minheap.push(node);

    while (!minheap.empty())
    {
        ListNode *node = minheap.top();
        minheap.pop();

        if (!head)
            head = tail = node;
        else
        {
            tail->next = node;
            tail = node;
        }

        if (node->next)
            minheap.push(node->next);
    }

    return head;
  }
};
 
int main(int argc, char *argv[]) {
  ListNode *l1 = new ListNode(2);
  l1->next = new ListNode(6);
  l1->next->next = new ListNode(8);
 
  ListNode *l2 = new ListNode(3);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(7);
 
  ListNode *l3 = new ListNode(1);
  l3->next = new ListNode(3);
  l3->next->next = new ListNode(4);
 
  ListNode *result = MergeKSortedLists::merge(vector<ListNode *>{l1, l2, l3});
  cout << "Here are the elements form the merged list: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}
