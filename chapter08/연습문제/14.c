int sumTree(TreeNode* root)
{
    if (root == NULL) return 0;
    int sum = 0;
    sum += root->key;
    sum += sumTree(root->left);
    sum += sumTree(root->right);
    return sum;
}