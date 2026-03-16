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
}