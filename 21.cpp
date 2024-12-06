// Convert BST to Max Heap
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void inorderTraversal(Node *root, vector<int> &arr)
{
    if (!root)
        return;
    inorderTraversal(root->left, arr);
    arr.push_back(root->data);
    inorderTraversal(root->right, arr);
}

void BSTToMaxHeap(Node *root, vector<int> &arr, int *i)
{
    if (!root)
        return;
    BSTToMaxHeap(root->left, arr, i);
    BSTToMaxHeap(root->right, arr, i);
    root->data = arr[++(*i)];
}

void convertToMaxHeapUtil(Node *root)
{
    vector<int> arr;
    int i = -1;
    inorderTraversal(root, arr);
    BSTToMaxHeap(root, arr, &i);
}

void postorderTraversal(Node *root)
{
    if (!root)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    convertToMaxHeapUtil(root);
    postorderTraversal(root);
    return 0;
}
