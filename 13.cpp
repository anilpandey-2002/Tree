class Solution
{
public:
  int countPairs(TreeNode *root, int distance)
  {
    int a = 0;
    dfs(root, distance, a);
    return a;
  }

private:
  vector<int> dfs(TreeNode *root, int distance, int &a)
  {
    vector<int> d(distance + 1, 0);
    if (!root)
      return d;
    if (!root->left && !root->right)
    {
      d[1] = 1;
      return d;
    }

    auto left = dfs(root->left, distance, a);
    auto right = dfs(root->right, distance, a);

    for (int l = 1; l <= distance; ++l)
      for (int r = 1; r <= distance; ++r)
        if (l + r <= distance)
          a += left[l] * right[r];

    for (int i = 1; i < distance; ++i)
      d[i + 1] = left[i] + right[i];

    return d;
  }
};
// Number of Good Leaf Nodes Pairs