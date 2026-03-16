#include "bst.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

typedef struct Node {
    int value;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

typedef struct BST {
    Node* root;
} BST;

typedef struct Iterator {
    Node* stack[STACK_SIZE];
    int top;
} Iterator;

/*task-h*/
Iterator* bstCreateIterator(BST* tree)
{
    if (tree == NULL || tree->root == NULL)
        return NULL;

    Iterator* iter = (Iterator*)malloc(sizeof(Iterator));
    if (!iter)
        return NULL;

    iter->top = -1;

    Node* current = tree->root;
    while (current != NULL) {
        if (iter->top >= STACK_SIZE - 1) {
            free(iter);
            return NULL;
        }
        iter->top++;
        iter->stack[iter->top] = current;
        current = current->leftChild;
    }

    return iter;
}

bool bstIteratorHasNext(Iterator* iter)
{
    return (iter != NULL && iter->top >= 0);
}

int bstIteratorNext(Iterator* iter)
{
    if (!bstIteratorHasNext(iter)) {
        return -1;
    }

    Node* current = iter->stack[iter->top];
    iter->top--;
    int value = current->value;

    if (current->rightChild != NULL) {
        current = current->rightChild;
        while (current != NULL) {
            if (iter->top >= STACK_SIZE - 1) {
                return value;
            }
            iter->top++;
            iter->stack[iter->top] = current;
            current = current->leftChild;
        }
    }

    return value;
}

void bstFreeIterator(Iterator* iter)
{
    if (iter == NULL)
        return;
    free(iter);
}

/*task - g*/
int bstKthMin(BST* tree, int k)
{
    if (!tree || k <= 0)
        return -1;

    Iterator* iter = bstCreateIterator(tree);
    if (!iter)
        return -1;

    int count = 0;
    int result = -1;

    while (bstIteratorHasNext(iter)) {
        int nextValue = bstIteratorNext(iter);
        count++;
        if (count == k) {
            result = nextValue;
            break;
        }
    }

    bstFreeIterator(iter);
    return result;
}
/*task-f*/
bool bstIsValid(BST* tree)
{
    if (!tree || !tree->root)
        return true;

    Iterator* iter = bstCreateIterator(tree);
    if (!bstIteratorHasNext(iter)) {
        bstFreeIterator(iter);
        return true;
    }

    int prevValue = bstIteratorNext(iter);
    while (bstIteratorHasNext(iter)) {
        int nextValue = bstIteratorNext(iter);
        if (nextValue <= prevValue) {
            bstFreeIterator(iter);
            return false;
        }
        prevValue = nextValue;
    }

    bstFreeIterator(iter);
    return true;
}

/*task-a*/
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
