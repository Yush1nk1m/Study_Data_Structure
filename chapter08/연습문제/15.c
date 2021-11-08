#include <stdio.h>

typedef struct TreeNode {
    int value;
    struct TreeNode *left, *right;
} TreeNode;

void underValuePrint(TreeNode* root, int value)
{
    if (root == NULL) return;
    
    if (root->value < value) printf("%d보다 작은 노드 : %d\n", value, root->value);
    
    if (root->left != NULL)
        underValuePrint(root->left, value);
    if (root->right != NULL)
        underValuePrint(root->right, value);

}