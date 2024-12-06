#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorder(TreeNode *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void preorder(TreeNode *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(TreeNode *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Inorder: ";
    inorder(root);
    cout << "\n";
    cout << "Preorder: ";
    preorder(root);
    cout << "\n";
    cout << "Postorder: ";
    postorder(root);
    cout << "\n";

    return 0;
}
