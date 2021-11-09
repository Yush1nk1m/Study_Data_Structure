void traversal_plus(TreeNode* root) {
    traversal_plus(root->left);
    root->key++;
    traversal_plus(root->right);
}