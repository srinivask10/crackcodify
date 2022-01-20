using namespace std;
 
#include <iostream>
 
class ListNode {
 public:
  int value = 0;
  ListNode *next;
 
  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};
 
class ReverseSubList {
 public:
  static ListNode *reverse(ListNode *head, int p, int q) {
    
    if (p == q)
        return head;

    ListNode *next, *prev, *current;
    current = head;
    next = prev = NULL;
    int i;

    for (i = 0; i < p-1 && current != NULL; i++)
    {
        prev = current;
        current = current->next;
    }

    ListNode *firstpartend = prev;
    ListNode *secondpartend = current;

    i = 0;
    while (current != NULL && i < q-p+1)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        i++;
    }

    if (firstpartend)
        firstpartend->next = prev;
    else
        head = prev;

    secondpartend->next = current;

    return head;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
 
  ListNode *result = ReverseSubList::reverse(head, 2, 4);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}
 

