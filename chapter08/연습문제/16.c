int oneChild(TreeNode* root)
{
    if (root == NULL) return 0;
    int sum = 0;
    if (root->left == NULL && root->right != NULL) {
        sum++;
        sum += oneChild(root->right);
    }
    else if (root->left != NULL && root->right == NULL) {
        sum++;
        sum += oneChild(root->left);
    }
    else {
        sum += oneChild(root->left);
        sum += oneChild(root->right);
    }
    return sum;
}