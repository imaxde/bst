#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{

    printf("Task B\n");
    printf("Inorder()");
    bstInorder(tree);

    printf("Preorder\n");
    bstPreorder(tree);

    printf("Postorder\n");
    bstPostorder(tree);
    return 0;
#include <stdbool.h>
#include <stdlib.h>

bool testBST(void)
{
    BST* tree = bstCreate();
    if (!tree)
        return false;

    bstInsert(tree, 1);
    bstInsert(tree, 2);
    bstInsert(tree, 3);

    bool result = bstContains(tree, 1) && bstContains(tree, 2) && bstContains(tree, 3) && !bstContains(tree, 4);

    bstFree(tree);
    return result;
}

int main(void)
{
    if (testBST())
        return 0;
    return 1;
}