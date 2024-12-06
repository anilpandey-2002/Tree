class Solution
{
public:
  int distributeCoins(TreeNode *root)
  {
    int a = 0;
    dfs(root, a);
    return a;
  }

private:
  int dfs(TreeNode *root, int &a)
  {
    if (!root)
      return 0;

    int l = dfs(root->l, a);
    int r = dfs(root->r, a);

    a += abs(l) + abs(r);
    return root->val + l + r - 1;
  }
}; // 979
// Distribute Coins in Binary Tree