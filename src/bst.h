#pragma once

typedef struct BST BST;
typedef struct Node Node;

// function for recursive tree traversal in order
void bstInorder(BST* tree);

// function for recursive tree traversal in preorder
void bstPreorder(BST* tree);

// function for recursive tree traversal in postorder
void bstPostorder(BST* tree);
#include <stdbool.h>

typedef struct Node Node;
typedef struct BST BST;

BST* bstCreate(void);
void bstInsert(BST* tree, int value);
bool bstContains(BST* tree, int value);
void bstFree(BST* tree);
