#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->right = node->left = NULL;
    return node;
}

void printExtremeNodes(Node *root)
{
    if (!root)
        return;

    queue<Node *> q;
    q.push(root);
    bool flag = false;

    while (!q.empty())
    {
        int nodeCount = q.size(), n = nodeCount;
        while (n--)
        {
            Node *curr = q.front();
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
            q.pop();
            if (flag && n == nodeCount - 1)
                cout << curr->data << " ";
            if (!flag && n == 0)
                cout << curr->data << " ";
        }
        flag = !flag;
    }
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(11);
    root->right->right->left = newNode(14);
    root->right->right->right = newNode(15);
    root->left->left->left->left = newNode(16);
    root->left->left->left->right = newNode(17);
    root->right->right->right->right = newNode(31);

    printExtremeNodes(root);
    return 0;
}
// Print extreme nodes of each level of Binary Tree in alternate order