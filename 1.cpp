class Solution
{
public:
  TreeNode *addOneRow(TreeNode *root, int v, int d)
  {
    if (d == 1)
    {
      TreeNode *a = new TreeNode(v);
      a->left = root;
      return a;
    }

    int b = 0;
    queue<TreeNode *> q{{root}};

    while (!q.empty())
    {
      ++b;
      for (int sz = q.size(); sz > 0; --sz)
      {
        TreeNode *node = q.front();
        q.pop();
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
        if (b == d - 1)
        {
          TreeNode *cachedLeft = node->left;
          TreeNode *cachedRight = node->right;
          node->left = new TreeNode(v);
          node->right = new TreeNode(v);
          node->left->left = cachedLeft;
          node->right->right = cachedRight;
        }
      }
      if (b == d - 1)
        break;
    }

    return root;
  }
}; // 623
// AddOneRowToTree