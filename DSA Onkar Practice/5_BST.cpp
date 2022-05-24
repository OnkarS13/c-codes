// struct node
// class private public
// constrcutor
// create
// insert
// input
// search
// min
// max
// mirror
// inorder
// preorder
// postorder
// depth
// display
//  main

#include <iostream>
#include <math.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

class Btree
{
    int n, x;

public:
    struct node *root;

    Btree()
    {
        root = NULL;
    }

    struct node *createNode(int key) // it will return a rot
    {
        struct node *ptr = new node; // like malloc
        ptr->data = key;
        ptr->left = NULL;
        ptr->right = NULL;
        return ptr; // ptr ko return kar do
    }

    struct node *insert(struct node *root, int key)
    {
        if (root == NULL)
        {
            root = createNode(key);
        }
        else if (key < root->data)
        {
            root->left = insert(root->left, key);
        }
        else
        {
            root->right = insert(root->right, key);
        }
        return root;
    }

    void input()
    {
        cout << "\nEnter number of elements in BST : ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Number = ";
            cin >> x;
            root = insert(root, x);
        }
    }

    int search(struct node *root, int key)
    {
        if (root != NULL)
        {
            while (root != NULL)
            {
                if (key == root->data)
                {
                    return 1;
                }
                else if (key < root->data)
                {
                    root = root->left;
                }
                else
                {
                    root = root->right;
                }
            }
        }
        else
        {
            return 0;
        }
    }

    void minValue(struct node *root)
    {
        while (root->left != NULL)
        {
            root = root->left;
        }
        cout << "\nMinimum :- " << root->data;
    }

    void maxValue(struct node *root)
    {
        while (root->right != NULL)
        {
            root = root->right;
        }
        cout << "\nMaximum :- " << root->data;
    }

    

    void inOrder(struct node *root)
    {
        if (root != NULL)
        {
            inOrder(root->left);
            cout << root->data << " ";
            inOrder(root->right);
        }
    }

    void preOrder(struct node *root)
    {
        if (root != NULL)
        {
            cout << root->data << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    void postOrder(struct node *root)
    {
        if (root != NULL)
        {
            postOrder(root->left);
            postOrder(root->right);
            cout << root->data << " ";
        }
    }

    void mirror(struct node *root)
    {
        if (root == NULL)
        {
            return;
        }
        else
        {
            struct node *ptr;
            mirror(root->left);
            mirror(root->right);

            //swapping
            ptr = root->left;
            root->left = root->right;
            root->right = ptr;
        }
        
    }

    int depth(struct node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        else
        {
            return (max(depth(root->left), depth(root->right)) + 1);
        }
    }
    void display()
    {
        cout << endl
             << "--- INORDER TRAVERSAL ---" << endl;
        inOrder(root);
        cout << endl;
        cout << endl
             << "--- POSTORDER TRAVERSAL ---" << endl;
        postOrder(root);
        cout << endl;
        cout << endl
             << "--- PREORDER TRAVERSAL ---" << endl;
        preOrder(root);
        cout << endl;
    }
};

int main()
{
    Btree B1;

    B1.input();
    B1.display();

    int a = 0;
    a = B1.search(B1.root, 5);
    if (a == 1)
    {
        cout << "\nElement found!!" << endl;
    }
    else
    {
        cout << "\nElement not found!!" << endl;
        cout << endl
             << a << endl;
    }

    B1.minValue(B1.root);
    B1.maxValue(B1.root);
    cout << endl;
    cout << "\n:-- Mirror image" << endl;
    B1.mirror(B1.root);
    B1.inOrder(B1.root);

    cout << "\n :-- Depth of tree:" << endl;
    cout << B1.depth(B1.root);

    return 0;
}