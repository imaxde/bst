#pragma once

typedef struct BST BST;
typedef struct Node Node;


// function for recursive tree traversal in order
void bstInorder(BST* tree);

// function for recursive tree traversal in preorder
void bstPreorder(BST* tree);

// function for recursive tree traversal in postorder
void bstPostorder(BST* tree);