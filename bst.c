#include <stdio.h>

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