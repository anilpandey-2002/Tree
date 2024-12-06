#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
  {
    unordered_map<int, TreeNode *> n;
    unordered_set<int> child;

    for (const auto &d : descriptions)
    {
      int p = d[0], c = d[1];
      bool isLeft = d[2];
      if (!n.count(p))
        n[p] = new TreeNode(p);
      if (!n.count(c))
        n[c] = new TreeNode(c);
      if (isLeft)
        n[p]->left = n[c];
      else
        n[p]->right = n[c];
      child.insert(c);
    }

    for (const auto &d : descriptions)
    {
      if (!child.count(d[0]))
        return n[d[0]];
    }

    return nullptr;
  }
};
// Create Binary Tree From Descriptions