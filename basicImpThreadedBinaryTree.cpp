#include <iostream>

struct Node
{
    int data;
    Node *right;
    Node *left;
    int thread;
};

Node *root = NULL;

Node *insert(Node *tree, Node *newNode, Node *rightThread)
{
    if (tree == NULL) {
        tree = newNode;
        if (rightThread != NULL) {
            tree -> right = rightThread;
            tree -> thread = 1;
        }
    } else if (newNode->data < tree->data) {
        tree->left = insert(tree->left, newNode, tree);
    } else if (tree->thread == 1) {
        tree->right = insert(NULL, newNode, rightThread);
        tree->thread = 0;
    } else {
        tree->right = insert(tree->right, newNode, rightThread);
    }

    return tree;
}

void createThreadedTree()
{
    Node *newNode;
    int num;
    std::cin >> num;
    while (num != -1)
    {
        newNode = (Node *)malloc(sizeof(Node));
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->data = num;
        root = insert(root, newNode, NULL);
        fflush(stdin);
        std::cin >> num;
    }
}

void inOrder(Node *tree)
{
    Node *ptrTraver = tree;
    Node *prevTraver = NULL;

    do
    {
        while (ptrTraver != NULL)
        {
            prevTraver = ptrTraver;
            ptrTraver = ptrTraver->left;
        }

        if (prevTraver != NULL)
        {
            std::cout << prevTraver->data << " ";
            ptrTraver = prevTraver->right;
            while (prevTraver != NULL && prevTraver->thread)
            {
                std::cout << ptrTraver->data << " ";
                prevTraver = ptrTraver;
                ptrTraver = ptrTraver->right;
            }
        }
    } while (ptrTraver != NULL);
};

int main()
{

    createThreadedTree();
    inOrder(root);
    return 0;
}