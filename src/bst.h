#pragma once

#include <stdbool.h>

typedef struct Node Node;
typedef struct BST BST;
typedef struct Iterator Iterator;

// iterator for not-recursion tree travials
// returns null only if memory allocation failed
Iterator* bstCreateIterator(BST* tree);

/*
these functions define programms behavior
if iterator is leaked.
first function check if elems for tree traviral
still exist,
and the second one return -1 if iterator is leaked
or memory allocation failed
*/
bool bstIteratorHasNext(Iterator* iter);
int bstIteratorNext(Iterator* iter);

// function"free" for iterator's memory
void bstFreeIterator(Iterator* iter);
/*Returns true if the tree is valid, and false otherwise.*/
bool bstIsValid(BST* tree);

// function for create tree
BST* bstCreate(void);

// function for inserting nodes
void bstInsert(BST* tree, int value);

// function check value of the node
bool bstContains(BST* tree, int value);

// function for free tree
void bstFree(BST* tree);