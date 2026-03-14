#pragma once
#include <stdbool.h>

typedef struct Node Node;
typedef struct BST BST;
typedef struct Iterator Iterator;

// iterator for not-recursion tree travials
Iterator* bstCreateIterator(BST* tree);

// function for checking if elems for travials still exist
bool bstIteratorHasNext(Iterator* iter);

// if iterator is empty, function returns -1
int bstIteratorNext(Iterator* iter);

// function"free" for iterator's memory
void bstFreeIterator(Iterator* iter);