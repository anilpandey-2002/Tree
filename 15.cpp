class Solution
{
public:
    bool path(TreeNode *root, int v, string &p)
    {
        if (root->val == v)
            return true;
        if (root->left && path(root->left, v, p))
            p.push_back('L');
        else if (root->right && path(root->right, v, p))
            p.push_back('R');
        return !p.empty();
    }

    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        string s1, s2;
        path(root, startValue, s1);
        path(root, destValue, s2);
        while (!s1.empty() && !s2.empty() && s1.back() == s2.back())
        {
            s1.pop_back();
            s2.pop_back();
        }
        return string(s1.size(), 'U') + string(rbegin(s2), rend(s2));
    }
};
// Step-By-Step Directions From a Binary Tree Node to Another