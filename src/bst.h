typedef struct BST BST;

// высота дерева
int bstHeight(BST* tree);

// количество узлов в бинарном дереве поиска
int bstSize(BST* tree);

// минимальное значение в дереве (если пусто, то возвращает минимально возможный int)
int bstMin(BST* tree);

// максимальное значение в дереве (если пусто, то возвращает максимально возможный int)
int bstMax(BST* tree);
