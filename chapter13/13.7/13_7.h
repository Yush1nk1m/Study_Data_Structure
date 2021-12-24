#include <stdio.h>
#include <stdlib.h>

// definition of AVL tree
typedef struct AVLNode
{
    int key;
    struct AVLNode* left;
    struct AVLNode* right;
} AVLNode;