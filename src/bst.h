#pragma once

#include <stdbool.h>

typedef struct BST BST;
typedef struct Node Node;

// function for create tree
BST* bstCreate(void);

// function for inserting nodes
void bstInsert(BST* tree, int value);

// function check value of the node
bool bstContains(BST* tree, int value);

// function for free tree
void bstFree(BST* tree);

// function for recursive tree traversal in order
void bstInorder(BST* tree);

// function for recursive tree traversal in preorder
void bstPreorder(BST* tree);

// function for recursive tree traversal in postorder
void bstPostorder(BST* tree);
