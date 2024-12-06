class Solution

{

public:
    vector<int> temp;

    bool solve(Node *root, int x, int y)
    {

        if (!root)
            return false;

        if (root->data <= x && root->data >= y)
        {

            temp.push_back(root->data);

            return true;
        }

        bool l, r;

        if (root->data > x && root->data > y)
        {

            l = solve(root->left, x, y);
        }

        if (root->data < x && root->data < y)
        {

            r = solve(root->right, x, y);
        }

        if (l || r)
            temp.push_back(root->data);

        return l || r;
    }

    /*You are required to complete below function */

    int kthCommonAncestor(Node *root, int k, int x, int y)

    {

        int maxi = max(x, y);

        int mini = min(x, y);

        solve(root, maxi, mini);

        if (temp.size() < k)
            return -1;

        for (int i = 0; i < temp.size(); i++)
        {

            if (i == k - 1)
                return temp[i];
        }
        return -1;
    }
};
// KthCommonAncestorinBST