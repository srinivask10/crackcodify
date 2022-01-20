using namespace std;
 
#include <deque>
#include <iostream>
#include <queue>
 
class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;
 
  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};
 
class ReverseLevelOrderTraversal {
 public:
  static deque<vector<int>> traverse(TreeNode *root) {
    deque<vector<int>> result = deque<vector<int>>();
    
    if (!root)
        return result;
    
    queue<TreeNode*> q;
    q.push(root);

    int sz, level = 0;
    while (!q.empty())
    {
        sz = q.size();
        vector<int> levelnodes;
        while (sz--)
        {
            TreeNode *node = q.front();
            q.pop();

            levelnodes.push_back(node->val);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        result.push_front(levelnodes);
    }

    return result;
  }
};
int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  auto result = ReverseLevelOrderTraversal::traverse(root);
 
  cout << "Reverse level order traversal: ";
  for (auto que : result) {
    for (auto num : que) {
      cout << num << " ";
    }
    cout << endl;
  }
}

