typedef struct BST BST;

// высота дерева
int bstHeight(BST* tree);

// количество узлов в бинарном дереве поиска
int bstSize(BST* tree);

// минимальное значение в дереве (если пусто, то возвращает 0)
int bstMin(BST* tree);

// максимальное значение в дереве (если пусто, то возвращает минимальное)
int bstMax(BST* tree);
