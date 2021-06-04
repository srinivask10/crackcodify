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


    return 0;
}

