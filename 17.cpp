class Solution
{
public:
  int sumNumbers(TreeNode *root)
  {
    int a = 0;
    dfs(root, 0, a);
    return a;
  }

private:
  void dfs(TreeNode *root, int path, int &a)
  {
    if (root == nullptr)
      return;
    if (root->left == nullptr && root->right == nullptr)
    {
      a += path * 10 + root->val;
      return;
    }

    dfs(root->left, path * 10 + root->val, a);
    dfs(root->right, path * 10 + root->val, a);
  }
}; // 129
// SumRoottoleafNumber