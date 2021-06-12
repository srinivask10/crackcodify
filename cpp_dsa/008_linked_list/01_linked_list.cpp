#include <iostream>

using namespace std;

class node
{
    public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insert_at_head(node* &head, int val)
{

    node *n = new node(val);
    n->next = head;
    head = n;
}

void insert_at_tail(node* &head, int val)
{
    node *n = new node(val);

    if (!head)
    {
        head = n;
        return;
    }

    node *temp = head;

    while (temp->next!=NULL)
        temp = temp->next;

    temp->next = n;
}

void display(node *head)
{
    node *temp = head;

    while (temp != NULL)
    {  
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

bool search(node * head, int key)
{
    node *temp  = head;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void delete_at_head(node* &head)
{
    node *todel = head;

    head = head->next;

    delete todel;
}

void deletion(node * &head, int val)
{
    if (!head)
        return;
    
    if (!head->next)
    {
        delete_at_head(head);
        return;
    }

    node *temp = head;
    while(temp->next->data != val)
        temp = temp->next;
    
    node *todel = temp->next;
    temp->next = temp->next->next;

    delete todel;
}

void reverse_list(node* &head)
{
    node *current = head;
    node *prev = NULL;
    node* next = head->next;

    while (current != NULL)
    {
        current->next = prev;

        prev = current;
        current = next;
        if (next)
            next = next->next;
    }

    head = prev;
}

node* kreverse(node* &head, int k)
{
    node *current = head;
    node *prev = NULL;
    node* next;

    int count = 0;
    while (current != NULL && count < k)
    {
        next = current->next;

        current->next = prev;

        prev = current;
        current = next;
        count++;
    }

    if (next)
        head->next = kreverse(next, k);

    return prev;
}


node* recursive_reverse(node *head)
{
    if (!head || !head->next)
        return head;

    node *newhead = recursive_reverse(head->next);

    head->next->next = head;
    head->next = NULL;

    return newhead;
}

int list_length(node *head)
{
    int len = 0;
    node* temp = head;

    while (temp!=NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void intersect(node *&h1, node *&h2, int pos)
{
    node *t1 = h1;
    pos--;

    while (pos--)
        t1 = t1->next;
    
    node* t2 = h2;
    while (t2->next != NULL)
        t2 = t2->next;

    t2->next = t1;
}

int intersection(node *head1, node *head2)
{
    int l1, l2;
    l1 = list_length(head1);
    l2 = list_length(head2);

    int d = 0;
    node *p1, *p2;

    if (l1 > l2)
    {
        d = l1 - l2;
        p1 = head1;
        p2 = head2;
    }
    else
    {
        d = l2 - l1;
        p1 = head2;
        p2 = head1;
    }

    while (d > 0)
    {
        d--;
        p1 = p1->next;
        if (p1 == NULL)
            return -1;
    }

    while (p1 != NULL && p2 != NULL)
    {
        if (p1 == p2)
            return p1->data;

        p1 = p1->next;
        p2 = p2->next;
    }

    return -1;

}

node* insert_last_k_at_start(node *head, int k)
{
    int len = 0;

    node* temp = head;

    while (temp!=NULL)
    {
        len++;
        temp = temp->next;
    }

    k = k % len;

    int i = 0;
    temp = head;
    node* new_tail = NULL;
    while (temp->next != NULL)
    {
        i++;
        if (i == (len - k))
            new_tail = temp;
        
        temp = temp->next;
    }

    temp->next = head;
    head = new_tail->next;
    new_tail->next = NULL;

    return head;
}

bool cycle_detection(node *head)
{
    node *fast, *slow;
    slow = fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}


//assume cycle is present.
void cycle_remove(node *head)
{
    node *fast, *slow;
    slow = fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);
    slow = head;

    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = NULL;
}

void make_cycle(node *head, int pos)
{
    node *temp = head;
    node *start;

    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
            start = temp;

        temp = temp->next;
        count++;
    }

    temp->next = start;
}

node* merge_sorted_lists_recursive(node *head1, node *head2)
{
    if (!head1)
        return head2;

    if (!head2)
        return head1;

    node *result;
    if (head1->data < head2->data)
    {
        result = head1;
        result->next = merge_sorted_lists_recursive(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = merge_sorted_lists_recursive(head1, head2->next);
    }
    return result;
}

node* merge_sorted_lists(node *head1, node *head2)
{
    node *p1 = head1, *p2 = head2, *head3, *p3;
    node *dummy = new node(-1);

    p3 = dummy;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }

    if (p1 != NULL)
        p3->next = p1;

    if (p2 != NULL)
        p3->next = p2;

    head3 = dummy->next;
    delete dummy;

    return head3;
}

//This is about the position, not the actual data in the node!
void put_even_position_elements_before_odd(node *head)
{
    node *odd = head;
    node* even = head->next;

    node *even_start = even;

    while (even->next != NULL && odd->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }

    odd->next = even_start;

    if (even->next)
        even->next = NULL;

}

int main()
{
    node *head = NULL;

    insert_at_tail(head, 1);
    insert_at_tail(head, 2);
    insert_at_tail(head, 3);
    insert_at_tail(head, 4);
    insert_at_tail(head, 5);
    insert_at_tail(head, 6);
    insert_at_tail(head, 7);
    //insert_at_head(head, 4);

    display(head);

    cout << search(head, 5) << endl;
    cout << search(head, 3) << endl;

    //deletion(head, 3);
    //delete_at_head(head);

    reverse_list(head);
    display(head);

    head = recursive_reverse(head);
    display(head);

    head = kreverse(head, 2);
    display(head);

    make_cycle(head, 3);
    //display(head);
    cout << "Cycle: " << cycle_detection(head) << endl;
    cycle_remove(head);
    
    display(head);
    cout << "Cycle: " << cycle_detection(head) << endl;

    head = insert_last_k_at_start(head, 3);
    display(head);

    node *head2 = NULL;
    insert_at_tail(head2, 1);
    insert_at_tail(head2, 2);
    insert_at_tail(head2, 3);
    insert_at_tail(head2, 4);
    insert_at_tail(head2, 5);
    insert_at_tail(head2, 6);    

    //intersect(head, head2, 3);
    cout << "After intersect: " << endl;
    display(head);
    display(head2);

    cout << "is interect: " << intersection(head, head2) << endl;

    node *l1 = NULL, *l2 = NULL;
    insert_at_tail(l1, 1);
    insert_at_tail(l1, 3);
    insert_at_tail(l1, 5);
    insert_at_tail(l1, 7);
    insert_at_tail(l1, 9);

    insert_at_tail(l2, 2);
    insert_at_tail(l2, 4);
    insert_at_tail(l2, 6);
    insert_at_tail(l2, 10);
    insert_at_tail(l2, 12);

    node *l3 = merge_sorted_lists(l1, l2);
    display(l3);



    node *ll1 = NULL, *ll2 = NULL;
    insert_at_tail(ll1, 1);
    insert_at_tail(ll1, 3);
    insert_at_tail(ll1, 5);
    insert_at_tail(ll1, 7);
    insert_at_tail(ll1, 9);

    insert_at_tail(ll2, 2);
    insert_at_tail(ll2, 4);
    insert_at_tail(ll2, 6);
    insert_at_tail(ll2, 10);
    insert_at_tail(ll2, 12);
    node *l4 = merge_sorted_lists_recursive(ll1, ll2);
    display(l4);


    node *oddeven = NULL;
    insert_at_tail(oddeven, 1);
    insert_at_tail(oddeven, 2);
    insert_at_tail(oddeven, 3);
    insert_at_tail(oddeven, 4);
    insert_at_tail(oddeven, 5);
    insert_at_tail(oddeven, 6);
    put_even_position_elements_before_odd(oddeven);
    display(oddeven);

    return 0;
}

