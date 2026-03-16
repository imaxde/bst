#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

typedef struct BST {
    Node* root;
} BST;

Node* createNode(int value)
{
    Node* node = malloc(sizeof(Node));
    if (node) {
        node->value = value;
        node->leftChild = NULL;
        node->rightChild = NULL;
    }
    return node;
}

BST* bstCreate(void)
{
    BST* tree = malloc(sizeof(BST));
    if (tree != NULL) {
        tree->root = NULL;
    }
    return tree;
}

Node* insertNode(Node* node, int value)
{
    if (node == NULL) {
        return createNode(value);
    }
    if (value < node->value) {
        node->leftChild = insertNode(node->leftChild, value);
    } else if (value > node->value) {
        node->rightChild = insertNode(node->rightChild, value);
    }
    return node;
}

void bstInsert(BST* tree, int value)
{
    if (tree != NULL) {
        tree->root = insertNode(tree->root, value);
    }
}

bool containsRec(Node* root, int value)
{
    if (root == NULL)
        return false;
    if (value == root->value)
        return true;
    if (value < root->value)
        return containsRec(root->leftChild, value);
    return containsRec(root->rightChild, value);
}

bool bstContains(BST* tree, int value)
{
    if (tree == NULL)
        return false;
    return containsRec(tree->root, value);
}

void freeNode(Node* node)
{
    if (node == NULL)
        return;
    freeNode(node->leftChild);
    freeNode(node->rightChild);
    free(node);
}

void bstFree(BST* tree)
{
    if (tree != NULL) {
        freeNode(tree->root);
        tree->root = NULL;
    }
}
