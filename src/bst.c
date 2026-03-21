#include "bst.h"
#include <stdbool.h>
#include <stdlib.h>


typedef struct Node {
    int value;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

typedef struct BST {
    Node* root;
} BST;

typedef struct Iterator {
    Node** stack;
    int top;
    int capacity;
} Iterator;

/*task-h*/
Iterator* bstCreateIterator(BST* tree)
{
    if (tree == NULL || tree->root == NULL)
        return NULL;

    Iterator* iter = malloc(sizeof(Iterator));
    if (!iter)
        return NULL;

    iter->top = -1;
    iter->capacity = 100;
    iter->stack = malloc(iter->capacity * sizeof(Node*));
    if (!iter->stack) {
        free(iter);
        return NULL;
    }

    Node* current = tree->root;
    while (current != NULL) {
        if (iter->top >= iter->capacity - 1) {
            int newCapacity = iter->capacity * 2;
            Node** newStack = realloc(iter->stack, newCapacity * sizeof(Node*));
            if (!newStack) {
                free(iter->stack);
                free(iter);
                return NULL;
            }
            iter->stack = newStack;
            iter->capacity = newCapacity;
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
            if (iter->top >= iter->capacity - 1) {
                int newCapacity = iter->capacity * 2;
                Node** newStack = realloc(iter->stack, newCapacity * sizeof(Node*));
                if (!newStack) {
                    return -1;
                iter->stack = newStack;
                iter->capacity = newCapacity;
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
    if (iter->stack)
        free(iter->stack);
    free(iter);
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