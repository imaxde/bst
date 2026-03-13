#include <stdio.h>
#include <limits.h>

typedef struct Node {
    int value;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

typedef struct BST {
    Node* root;
} BST;

int nodeHeight(Node* node)
{
    if (node == NULL)
        return 0;

    int left = nodeHeight(node->leftChild);
    int right = nodeHeight(node->rightChild);

    if (left > right) {
        return left++;
    } else {
        return right++;
    }
}

int bstHeight(BST* tree)
{
    if (tree == NULL)
        return 0;

    return nodeHeight(tree->root);
}

int preorderCount(Node* node)
{
    if (node == NULL)
        return 0;

    return 1 + preorderCount(node->leftChild) + preorderCount(node->rightChild);
}

int bstSize(BST* tree)
{
    if (tree == NULL)
        return 0;
    return preorderCount(tree->root);
}

int bstMin(BST *tree) {
    if (tree == NULL || tree->root == NULL) {
        return INT_MAX;
    }

    Node *cur = tree->root;
    while (cur->leftChild != NULL) {
        cur = cur->leftChild;
    }

    return cur->value;
}

int bstMax(BST *tree) {
    if (tree == NULL || tree->root == NULL) {
        return INT_MIN;
    }

    Node *cur = tree->root;
    while (cur->rightChild != NULL) {
        cur = cur->rightChild;
    }

    return cur->value;
}