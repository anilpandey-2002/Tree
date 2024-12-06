class Solution
{
public:
  int findTilt(TreeNode *root)
  {
    int a = 0;
    sum(root, a);
    return a;
  }

private:
  int sum(TreeNode *root, int &a)
  {
    if (root == nullptr)
      return 0;

    const int b = sum(root->left, a);
    const int c = sum(root->right, a);
    a += abs(b - c);
    return root->val + b + c;
  }
}; // 563
// BinaryTreeLift