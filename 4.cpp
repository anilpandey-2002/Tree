// Given the root of a binary tree, return the leftmost value in the last row of the tree
class Solution
{
public:
  int findBottomLeftValue(TreeNode *root)
  {
    queue<TreeNode *> a{{root}};
    TreeNode *node = nullptr;

    while (!a.empty())
    {
      node = a.front();
      a.pop();
      if (node->right)
        a.push(node->right);
      if (node->left)
        a.push(node->left);
    }

    return node->val;
  }
};
// BottomleftTree