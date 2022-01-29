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
 
class PalindromicLinkedList {
 public:
    static void printlist(ListNode *head)
    {
        while (head)
        {  
            cout << head->value << " ";
            head = head->next;
        }
        cout << endl;
    }

    static ListNode* reverse(ListNode *head)
    {
        ListNode *next, *prev, *current;

        prev = next = NULL;
        current = head;

        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
 
        return prev;
    }

  static bool isPalindrome(ListNode *head) {

    if (!head || !head->next)
        return true;

    ListNode *slow, *fast;
    slow = fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *secondstart = reverse(slow);
    ListNode *middle = secondstart;
    
    while (head != NULL && secondstart != NULL)
    {
        if (secondstart->value != head->value)
            break;
        head = head->next;
        secondstart = secondstart->next;
    }

    reverse(middle);

    if (!head || !secondstart)
        return true;

    return false;
  }
};
 
int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(2);
  head->next = new ListNode(4);
  head->next->next = new ListNode(6);
  head->next->next->next = new ListNode(6);
  head->next->next->next->next = new ListNode(4);
  cout << "Is palindrome: " << PalindromicLinkedList::isPalindrome(head) << endl;

  head->next->next->next->next->next = new ListNode(2);
  cout << "Is palindrome: " << PalindromicLinkedList::isPalindrome(head) << endl;
}

