#include <vector>

using namespace std;

struct tree_node
{
	int data;
	struct tree_node *left, *right;
};

tree_node* get_new_tree_node(int data);
void destroy_tree(tree_node *root);
tree_node* get_tree_from_list(vector<int> a);
tree_node* get_tree_from_user();
void traverse_print_tree(tree_node *root);
void print_tree(tree_node *root);
void insert_tree_node(tree_node **root, int data);
bool is_tree_height_balanced(tree_node *root);
