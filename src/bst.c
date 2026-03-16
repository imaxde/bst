#include "bst.h"
#include <stdbool.h>
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

int bstKthMin(BST* tree, int k)
{
    if (!tree || k <= 0)
        return -1; 

    Iterator* iter = iteratorInit(tree);
    int count = 0;
    int result = -1;

    while (iteratorHasNext(iter)) {
        int nextValue = iteratorNext(iter);
        count++;
        if (count == k) {
            result = nextValue;
            break;
        }
    }

    iteratorFree(iter);
    return result;
}