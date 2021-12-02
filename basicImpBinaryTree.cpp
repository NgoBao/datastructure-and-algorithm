#include <iostream>

struct Node {
    int data;
    Node * left;
    Node * right;
};

class BinaryTree {
    public:
        Node * root;

        BinaryTree() {
            root = NULL;
        }

        void insert(int data);
        void preOrderTraversal(Node * tree);
        void inOrderTraversal(Node * tree);
        void postOrderTraversal(Node * tree);
        Node * findSmallestNode(Node * tree);
        Node * findLargestNode(Node * tree);
        Node * deleteNode(Node * tree, int data);
        Node * mirrorImage(Node * subTree);
        int totalNodes(Node * tree);
        int totalExternalNodes(Node * tree);
        int totalInternalNodes(Node * tree);
        int height();
        int deleteTree(Node * subTree);
};

void BinaryTree::insert(int data) {
    Node * newNode = (Node *) malloc(sizeof(Node));
        newNode -> data = data;
        newNode -> left = NULL;
        newNode -> right = NULL;

    if (root == NULL) {
        root = newNode;
        return;
    } 

    Node * ptrTraver = root;
    Node * ptrCurrentTraver = NULL;

    while (ptrTraver != NULL) {
        ptrCurrentTraver = ptrTraver;
        if (data < ptrTraver -> data) {
            ptrTraver = ptrTraver -> left;
        } else {
            ptrTraver = ptrTraver -> right;
        }
    }

    if (data < ptrCurrentTraver -> data) {
        ptrCurrentTraver -> left = newNode;
    } else {
        ptrCurrentTraver -> right = newNode;
    }
}

void BinaryTree::preOrderTraversal(Node * tree) {
    if (tree != NULL) {
        std::cout << tree -> data << std::endl;
        preOrderTraversal(tree -> left);
        preOrderTraversal(tree -> right);
    }
}

void BinaryTree::inOrderTraversal(Node * tree) {
    if (tree != NULL) {
        inOrderTraversal(tree -> left);
        std::cout << tree -> data << std::endl;
        inOrderTraversal(tree -> right);
    }
}

void BinaryTree::postOrderTraversal(Node * tree) {
    if (tree != NULL) {
        postOrderTraversal(tree -> left);
        postOrderTraversal(tree -> right);
        std::cout << tree -> data << std::endl;
    }
}

Node * BinaryTree::findLargestNode(Node * tree) {
    if (tree == NULL || tree -> right == NULL) return tree;
    return findLargestNode(tree -> right);
}

Node * BinaryTree::findSmallestNode(Node * tree) {
    if (tree == NULL || tree -> left == NULL) return tree;
    return findSmallestNode(tree ->  left);
}

Node * BinaryTree::deleteNode(Node * tree, int data) {
    if (tree == NULL) return tree;
    if (data < tree -> data) {
        tree -> left = deleteNode(tree -> left, data);
    } else if (data > tree -> data) {
        tree -> right = deleteNode(tree -> right, data);
    } else {
        if (tree -> left == NULL && tree -> right == NULL) return NULL;
        if (tree -> left == NULL) {
            Node * temp = tree -> right;
            free(tree);
            return temp;
        }

        if (tree -> right == NULL) {
            Node * temp = tree -> left;
            free(tree);
            return temp;
        }

        Node * temp = findSmallestNode(tree -> right);
        tree -> data = temp -> data;
        tree -> right = deleteNode(tree -> right, temp -> data);
    }

}

Node * BinaryTree::mirrorImage(Node * tree) {
    Node * temp;
    if (tree != NULL) {
        mirrorImage(tree -> left);
        mirrorImage(tree -> right);
        temp = tree -> left;
        tree -> left = tree -> right;
        tree -> right = temp; 
    }
}

int BinaryTree::totalNodes(Node * tree) {
    if (tree == NULL) return 0;
    return totalNodes (tree -> left) + totalNodes(tree -> right) + 1;
}

int BinaryTree::totalExternalNodes(Node * tree) {
    if (tree == NULL) return 0;
    if (tree -> left == NULL && tree -> right == NULL) return 1;
    return totalExternalNodes(tree -> left) + totalExternalNodes(tree -> right); 
}

int BinaryTree::totalInternalNodes(Node * tree) {
    if (
        tree == NULL ||
        (tree -> left == NULL && tree -> right == NULL)
    ) return 0;

    return totalInternalNodes(tree -> left) + totalInternalNodes(tree -> right);
}

int BinaryTree::height(Node * tree) {
    int leftHeight, rightHeight;
    
    if (tree == NULL) return 0;
    
    leftHeight = height(tree -> left);
    rightHeight = height(tree -> right);

    if ( leftHeight > rightHeight ) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

Node * BinaryTree::deleteTree(Node * tree) {
    if (tree != NULL) {
        deleteTree(tree -> left);
        deleteTree(tree -> right);
        free(tree);
    }
}

int main() {
    BinaryTree treeOne;

    treeOne.insert(15);
    treeOne.insert(11);
    treeOne.insert(26);
    treeOne.insert(8);
    treeOne.insert(20);
    std::cout << treeOne.findLargestNode(treeOne.root) -> data << std::endl;
    treeOne.deleteNode(treeOne.root, 8);
    treeOne.preOrderTraversal(treeOne.root);

    return 0;
}