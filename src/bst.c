#include "bst.h"

typedef struct Node {
    int value;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

typedef struct BST {
    Node *root;
} BST;

void bstInorder(BST* tree) {
    if (tree == NULL || tree->root == NULL) {
        return;
    }
    void inorder(Node* node) {
        if (node == NULL) return;
        inorder(node->leftChild);
        inorder(node->rightChild);
    }
    inorder(tree->root);
}

void bstPreorder(BST* tree) {
    if (tree == NULL || tree->root == NULL) {
        return;
    }
    void preorder(Node* node) {
        if (node == NULL) return;
        preorder(node->leftChild);
        preorder(node->rightChild);
    }
    
    preorder(tree->root);
}

void bstPostorder(BST* tree) {
    if (tree == NULL || tree->root == NULL) {
        return;
    }
    
    void postorder(Node* node) {
        if (node == NULL) return;
        postorder(node->leftChild);
        postorder(node->rightChild);
    }
    
    postorder(tree->root);
}