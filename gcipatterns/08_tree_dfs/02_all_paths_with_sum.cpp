using namespace std;
 
#include <iostream>
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
 
class FindAllTreePaths {
 public:
  static vector<vector<int>> findPaths(TreeNode *root, int sum) {
    vector<vector<int>> allPaths;
    vector<int> curpath;
    findRecPath(root, sum, curpath, allPaths);

    return allPaths;
  }

  static void findRecPath(TreeNode *root, int sum, vector<int> &curpath, vector<vector<int>> &allPaths)
  {
      if (!root)
        return;

      curpath.push_back(root->val);

      if (sum == root->val && !root->left && !root->right)
          allPaths.push_back(curpath);
    else
    {
    
      findRecPath(root->left, sum - root->val, curpath, allPaths);
      findRecPath(root->right, sum - root->val, curpath, allPaths);
    }
    curpath.pop_back();
  }
};
 
int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  int sum = 23;
  vector<vector<int>> result = FindAllTreePaths::findPaths(root, sum);
  cout << "Tree paths with sum " << sum << ": " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}

