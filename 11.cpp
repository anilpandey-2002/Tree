// Given the root of a binary tree, invert the tree, and return its root.
class Solution
{
public:
  TreeNode *invertTree(TreeNode *root)
  {
    if (root == nullptr)
      return nullptr;

    TreeNode *const left = root->left;
    TreeNode *const right = root->right;
    root->left = invertTree(right);
    root->right = invertTree(left);
    return root;
  }
};
// Invert_BT