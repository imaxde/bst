#pragma once

typedef struct Node {
    int value;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

typedef struct BST {
    Node* root;
} BST;

// functions for tree travials
void bstInorder(BST* tree);
void bstPreorder(BST* tree);
void bstPostorder(BST* tree);
