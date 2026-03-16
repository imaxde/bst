#include "bst.h"
#include <stdbool.h>
#include <stdio.h>

static bool testBST(void)
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
    BST* tree = bstCreate();
    if (!tree) {
        return 1;
    }

    bstInsert(tree, 5);
    bstInsert(tree, 3);

    printf("Inorder: ");
    bstInorder(tree);

    printf("Preorder: ");
    bstPreorder(tree);

    printf("Postorder: ");
    bstPostorder(tree);

    bstFree(tree);

    if (testBST()) {
        printf("All tests have passed\n");
        return 0;
    }
    return 1;
}
