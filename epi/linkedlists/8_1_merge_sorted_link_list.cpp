#include <iostream>
#include <single_link_list.h>

int main()
{
	list_node *list1 = NULL, *list2 = NULL;
      	
       	cout << "Enter sorted list 1:" << endl;
	list1 = get_link_list_from_user();

       	cout << "Enter sorted list 2:" << endl;
	list2 = get_link_list_from_user();
	
	//Check single_link_list.cpp file for following function defination.
	list_node *merge = merge_sorted_link_lists(list1, list2);

	print_link_list(list1);
	print_link_list(list2);
	print_link_list(merge);
	return 0;
}
