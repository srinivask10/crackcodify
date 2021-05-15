#include <tree.h>
#include <iostream>

using namespace std;

int main()
{
	tree_node *root = get_tree_from_user();
	print_tree(root);
	bool is_balanced = is_tree_height_balanced(root);
	cout << "Tree is height balanced: " << is_balanced << endl;

	return 0;
}
