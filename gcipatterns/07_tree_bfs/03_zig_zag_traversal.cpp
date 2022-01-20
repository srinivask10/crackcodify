using namespace std;
 
#include <iostream>
#include <queue>
#include <vector>
 
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
 
class ZigzagTraversal {
 public:
  static vector<vector<int>> traverse(TreeNode *root) {
    vector<vector<int>> result;
    
    if (!root)
        return result;
    
    queue<TreeNode*> q;
    q.push(root);

    int idx, sz, leveldir = 0;
    while (!q.empty())
    {
        idx = sz = q.size();
        vector<int> levelnodes(sz);
        
        while (idx--)
        {
            TreeNode *node = q.front();
            q.pop();

            if (!leveldir)
                levelnodes[sz - idx - 1] = node->val;
            else
                levelnodes[idx] = node->val;
            
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        
        leveldir = !leveldir;
        result.push_back(levelnodes);
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
  root->right->left->left = new TreeNode(20);
  root->right->left->right = new TreeNode(17);
  vector<vector<int>> result = ZigzagTraversal::traverse(root);
  cout << "Zigzag traversal: ";
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}

