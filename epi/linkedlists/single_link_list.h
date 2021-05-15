#include <vector>

using namespace std;

struct list_node
{

	int data;
	list_node *next;

};


list_node* get_new_list_node(int data);
void destroy_list(list_node *head);
list_node* get_link_list(vector<int> a);
list_node* get_link_list_from_user();
void print_link_list(list_node *head);
list_node* merge_sorted_link_lists(list_node *list1,  list_node *list2);
