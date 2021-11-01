/* 02. 이진 트리에서 비단말노드의 개수를 계산하는 함수 get_nonleaf_count(TreeNode* t)를 작성해보자. */

#include <stdio.h>
#include <stdlib.h>
#define max(a, b) ((a >= b) ? a : b) 

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

int get_node_count(TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + get_node_count(root->left) + get_node_count(root->right);
}

int get_leaf_count(TreeNode* root) {
    if (root == NULL) return 0;
    
    if (root->left == NULL && root->right == NULL) return 1;
    else return get_leaf_count(root->left) + get_leaf_count(root->right);
}

int get_height(TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + max(get_height(root->left), get_height(root->right));
}

int get_nonleaf_count(TreeNode* t) {
    return get_node_count(t) - get_leaf_count(t);
}

int main(void) {
    TreeNode n24 = { 24, NULL, NULL };
    TreeNode n12 = { 12, &n24, NULL };
    TreeNode n6 = { 6, &n12, NULL };
    TreeNode n7 = { 7, NULL, NULL };
    TreeNode n3 = { 3, &n6, &n7 };
    TreeNode n8 = { 8, NULL, NULL };
    TreeNode n9 = { 9, NULL, NULL };
    TreeNode n4 = { 4, &n8, &n9 };
    TreeNode n5 = { 5, NULL, NULL };
    TreeNode n2 = { 2, &n4, &n5 };
    TreeNode n1 = { 1, &n2, &n3 };
    TreeNode* root = &n1;

    printf("the number of nodes : %d\n", get_node_count(root));
    printf("the number of leaf nodes : %d\n", get_leaf_count(root));
    printf("the height of tree : %d\n", get_height(root));
    printf("the number of non-leaf nodes : %d\n", get_nonleaf_count(root));

    return 0;
}