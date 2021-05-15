#include <tree.h>
#include <iostream>

tree_node* get_new_tree_node(int data)
{
	tree_node *node = new tree_node;
	if (!node)
		return NULL;

	node->left = node->right = NULL;
	node->data = data;

	return node;
}

void destroy_tree(tree_node *root)
{

}

tree_node* get_tree_from_list(vector <int> a)
{
	tree_node *root = NULL;
	for (auto num : a)
		insert_tree_node(&root, num);

	return root;
}

tree_node* get_tree_from_user()
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

	return get_tree_from_list(arr);
}


void traverse_print_tree(tree_node *root)
{
	if (root)
	{
		if (root->left)	
			traverse_print_tree(root->left);

		cout << root->data << " ";

		if (root->right) 
			traverse_print_tree(root->right);
	}
}

void print_tree(tree_node *root)
{
	traverse_print_tree(root);
	cout << endl;
}



void insert_tree_node(tree_node **root, int data)
{
	tree_node *node = get_new_tree_node(data);

	if (*root==NULL)
	{
		*root = node;
	}
	else
	{
		tree_node *traverse = *root;
		while (true)
		{
			if (data < traverse->data)
			{
				if (traverse->left)
				{
					traverse = traverse->left;
					continue;
				}
				else
				{
					traverse->left = node;
					break;
				}
			}
			else
			{
				if (traverse->right)
				{
					traverse = traverse->right;
					continue;
				}
				else
				{
					traverse->right = node;
					break;
				}
			}
		}
	}
}


int check_tree_height_balanced(tree_node *root, bool &is_balanced)
{
	if (!root)
		return 0;
	int left = check_tree_height_balanced(root->left, is_balanced);
	int right = check_tree_height_balanced(root->right, is_balanced);
	if ((left - right) < -1 || (left - right) > 1)
		is_balanced = false;
	return 1+max(left, right);
}


bool is_tree_height_balanced(tree_node *root)
{
	bool is_balanced = true;
	check_tree_height_balanced(root, is_balanced);

	return is_balanced;
}

