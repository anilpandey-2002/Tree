class Solution
{
public:
    void trav(Node *root, vector<int> &ans)
    {
        if (!root)
            return;
        ans.push_back(root->val);
        for (auto i : root->children)
            trav(i, ans);
    }
    vector<int> preorder(Node *root)
    {
        vector<int> ans;
        trav(root, ans);
        return ans;
    }
};
// 589. N-ary Tree Preorder Traversal