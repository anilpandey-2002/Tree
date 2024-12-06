class Solution
{
public:
  int sumOfLeftLeaves(TreeNode *root)
  {
    if (root == nullptr)
      return 0;

    int a = 0;

    if (root->left)
    {
      if (root->left->left == nullptr && root->left->right == nullptr)
        a += root->left->val;
      else
        a += sumOfLeftLeaves(root->left);
    }
    a += sumOfLeftLeaves(root->right);

    return a;
  }
}; // 404
// SumOfLeftLeaves