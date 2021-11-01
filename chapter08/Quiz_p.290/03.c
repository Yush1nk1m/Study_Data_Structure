/* 03. 두 개의 트리가 같은 구조를 가지고 있고, 대응되는 노드들이 같은 데이터를 가지고 있는지를 검사하는 함수
       equal(TreeNode* t1, TreeNode* t2)를 작성해보자. 여기서 t1과 t2는 트리의 루트 노드를 가리키는 포인터이다. */

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

int equal(TreeNode* t1, TreeNode* t2) {
    if (t1 == NULL && t2 == NULL) return 1;
    else if ((t1 == NULL && t2 != NULL) || (t1 != NULL && t2 == NULL)) return 0;
    
    if (t1->data != t2->data) return 0;
    else {
        int count = (equal(t1->left, t2->left) + equal(t1->right, t2->right));
        //printf("count : %d\n", count);
        if (count % 2 == 0) return 1;
        else return 0;
    }
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
    printf("equal? : %s\n", (equal(root, root) ? "True" : "False"));

    return 0;
}