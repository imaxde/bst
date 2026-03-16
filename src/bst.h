#pragma once
#include <stdbool.h>

typedef struct Node Node;
typedef struct BST BST;

BST* bstCreate(void);
void bstInsert(BST* tree, int value);
bool bstContains(BST* tree, int value);
void bstFree(BST* tree);