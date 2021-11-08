#define min(A, B) (A > B) ? B : A
#define max(A, B) (A > B) ? A : B

int minimum(TreeNode* root) {
    int MIN = root->key;
    if (root->left != NULL)
        MIN = min(MIN, minimum(root->left));
    if (root->right != NULL)
        MIN = min(MIN, minimum(root->right));
    return MIN;
}

int maximum(TreeNode* root) {
    int MAX = root->key;
    if (root->left != NULL)
        MAX = max(MAX, maximum(root->left));
    if (root->right != NULL)
        MAX = max(MAX, maximum(root->right));
    return MAX;
}

void printMinMax(TreeNode* root) {
    printf("최소값 = %d\n최대값 = %d\n", minimum(root), maximum(root));
}