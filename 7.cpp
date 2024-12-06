class Solution
{
public:
  vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
  {
    unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
    vector<TreeNode *> a;
    dfs(root, toDeleteSet, true, a);
    return a;
  }

private:
  TreeNode *dfs(TreeNode *root, const unordered_set<int> &toDeleteSet, bool isRoot, vector<TreeNode *> &a)
  {
    if (!root)
      return nullptr;
    bool deleted = toDeleteSet.count(root->val);
    if (isRoot && !deleted)
      a.push_back(root);
    root->left = dfs(root->left, toDeleteSet, deleted, a);
    root->right = dfs(root->right, toDeleteSet, deleted, a);
    return deleted ? nullptr : root;
  }
};
// Delete Nodes And Return Forest