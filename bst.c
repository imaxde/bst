#include "bst.h"
#include <stdio.h>

// extra functions for recursion for tree travercal
static void inOrder(Node* node)
{
    if (node == NULL) {
        return;
    }

    inOrder(node->leftChild);
    printf("%d ", node->value);
    inOrder(node->rightChild);
}

static void preOrder(Node* node)
{
    if (node == NULL) {
        return;
    }

    printf("%d ", node->value);
    preOrder(node->leftChild);
    preOrder(node->rightChild);
}

static void postOrder(Node* node)
{
    if (node == NULL) {
        return;
    }

    postOrder(node->leftChild);
    postOrder(node->rightChild);
    printf("%d ", node->value);
}

void bstInOrder(BST* tree)
{
    if (tree == NULL || tree->root == NULL) {
        return;
    }
    inOrder(tree->root);
    printf("\n");
}

void bstPreOrder(BST* tree)
{
    if (tree == NULL || tree->root == NULL) {
        return;
    }
    preOrder(tree->root);
    printf("\n");
}

void bstPostOrder(BST* tree)
{
    if (tree == NULL || tree->root == NULL) {
        return;
    }
    postOrder(tree->root);
    printf("\n");
}