class Solution
{
public:
    bool isEvenOddTree(TreeNode *root)
    {
        if (!root)
            return true;

        queue<TreeNode *> q;
        q.push(root);
        bool isEven = true;

        while (!q.empty())
        {
            int prevVal = isEven ? INT_MIN : INT_MAX;
            int sz = q.size();
            bool isValidLevel = true;
            while (sz--)
            {
                TreeNode *node = q.front();
                q.pop();

                if ((isEven && (node->val % 2 == 0 || node->val <= prevVal)) ||
                    (!isEven && (node->val % 2 == 1 || node->val >= prevVal)))
                {
                    isValidLevel = false;
                    break;
                }

                prevVal = node->val;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            if (!isValidLevel)
                return false;
            isEven = !isEven;
        }

        return true;
    }
};
// EvenOddTree