#include <single_link_list.h>
#include <iostream>


using namespace std;

list_node* get_new_list_node(int data)
{
	list_node* node = new list_node;
	
	if (!node)
		return NULL;

	node->data = data;
	node->next = NULL;

	return node;
}

void destroy_list(list_node *head)
{
	if (!head)
		return;

	list_node *t;

	while (head != NULL)
	{
		t = head->next;
		delete head;
	}
}

list_node* get_link_list(vector<int> a)
{
	list_node *head = NULL, *cur = NULL;

	if (!a.size())
		return NULL;
	
	head = get_new_list_node(a[0]);
	cur = head;

	for (int i = 1; i < a.size(); i++)
	{
		cur->next = get_new_list_node(a[i]);
		cur = cur->next;
	}

	return head;
}


list_node* get_link_list_from_user()
{
	int num, n;
	vector<int> arr;

	cout << "Enter number of elements: " << endl;
	cin >> num;

	cout << "Enter elements: " << endl;
	for (int i = 0; i < num; i++)
	{
		cin >> n;
		arr.push_back(n);
	}

	return get_link_list(arr);
}

void print_link_list(list_node *head)
{
	if (!head)
	{
		cout << "Linked list empty." << endl;
		return;
	}
	cout << "Contents of link list: " << endl;

	while (head)
	{
		cout << head->data << "\t";
		head = head->next;
	}
	cout << endl;
}


list_node* merge_sorted_link_lists(list_node *list1,  list_node *list2)
{
	list_node *merge = NULL, *merge_head = NULL;

	if (!list1)
		return list2;
	if (!list2)
		return list1;

	//Handle first element.
	if (list1->data < list2->data)
	{
		merge_head = list1;
		list1 = list1->next;
	}
	else
	{
		merge_head = list2;
		list2 = list2->next;
	}
	merge_head->next = NULL;

	merge = merge_head;
	
	//Merge remaining till one of the list is empty.
	while (list1 && list2)
	{
		if (list1->data < list2->data)
		{
			merge->next = list1;
			list1 = list1->next;
		}
		else
		{
			merge->next = list2;
			list2 = list2->next;
		}
		merge = merge->next;
	}

	while (list1)
	{
		merge->next = list1;
		list1 = list1->next;
		merge = merge->next;
	}
	while (list2)
	{
		merge->next = list2;
		list2 = list2->next;
		merge = merge->next;
	}

	return merge_head;
}


