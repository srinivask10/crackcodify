using namespace std; 
#include <iostream> 
class ListNode 
{ 
    public:  
    int value = 0;  
    ListNode *next;   
    ListNode(int value) 
    {    
        this->value = value;    
        next = nullptr;  
    }
}; 

class LinkedListCycleStart {
    public: 
    static int getLength(ListNode *node) {
        int len = 0;

        ListNode *cur = node;

        do
        {
            cur = cur->next;
            len++;
        }while (cur != node);

        return len;
    }

    static ListNode *findCycleStart(ListNode *head) {
        ListNode *slow, *fast;
        bool cycle = false;

        cout << endl;
        slow = fast = head;
        while (fast != NULL && fast->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                cycle = true;
                break;
            }
        }

        if (!cycle)
            return head;        //Not returning NULL.

        int len = getLength(slow);
        ListNode *t1, *t2;

        t1 = t2 = head;
        while (len>0)
        {
            t1 = t1->next;
            len--;
        }
        
        while (t1 != t2)
        {
            t1 = t1->next;
            t2 = t2->next;
        }

        return t1;
    }
};

int main(int argc, char *argv[]) {  ListNode *head = new ListNode(1);  head->next = new ListNode(2);  head->next->next = new ListNode(3);  head->next->next->next = new ListNode(4);  head->next->next->next->next = new ListNode(5);  head->next->next->next->next->next = new ListNode(6);   head->next->next->next->next->next->next = head->next->next;  cout << "LinkedList cycle start: " << LinkedListCycleStart::findCycleStart(head)->value << endl;   head->next->next->next->next->next->next = head->next->next->next;  cout << "LinkedList cycle start: " << LinkedListCycleStart::findCycleStart(head)->value << endl;   head->next->next->next->next->next->next = head;  cout << "LinkedList cycle start: " << LinkedListCycleStart::findCycleStart(head)->value << endl;} 
