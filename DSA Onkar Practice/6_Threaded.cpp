// struct node

// createThreaded
// new node
// leftmost
// inorder

// main

#include <iostream>
using namespace std;

struct node
{
    int key;
    struct node *left;
    struct node *right;
    bool isThreaded;
};

struct node *createthreded(struct node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->left == NULL && root->right == NULL) // only root is present
    {
        return root;
    }

    if (root->left != NULL)
    {
        struct node *l = createthreded(root->left);

        l->right = root;
        l->isThreaded = true;
    }

    if (root->right == NULL)
    {
        return root;
    }

    return createthreded(root->right);
}

struct node *newNode(int key)
{
    struct node *ptr = new node;
    ptr->key = key;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

struct node *leftMost(struct node *root)
{
    while (root != NULL && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

void inOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    struct node *current = leftMost(root);

    while (current != NULL)
    {
        cout << current->key << " ";

        if (current->isThreaded)
        {
            current = current->right;
        }
        else
        {
            current = leftMost(current->right);
        }
    }
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    createthreded(root);
    cout << "Inorder traversal of created "
            "threaded tree is\n";
    inOrder(root);
    return 0;
}