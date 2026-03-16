#pragma once
#include <stdbool.h>

typedef struct Node Node;
typedef struct BST BST;
typedef struct Iterator Iterator;

// iterator for not-recursion tree travials
Iterator* bstCreateIterator(BST* tree);

/*
these functions define programms behavior
if iterator is leaked.
first function check if elems for tree traviral
still exist,
and the second one return -1 if iterator is leaked
*/
bool bstIteratorHasNext(Iterator* iter);
int bstIteratorNext(Iterator* iter);

// function"free" for iterator's memory
void bstFreeIterator(Iterator* iter);
/*
 Returns the k-th smallest element in the BST (k starts from 1).
 If k <= 0 or k > number of elements in the tree or the tree is empty, the function returns -1
 */
int bstKthMin(BST* tree, int k);

BST* bstCreate(void);
void bstInsert(BST* tree, int value);
bool bstContains(BST* tree, int value);
void bstFree(BST* tree);
