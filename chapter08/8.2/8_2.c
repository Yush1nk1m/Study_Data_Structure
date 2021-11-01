// 중위 순회 (inorder traversal)
void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);            // traversal left subtree
        printf("[%d] ", root->data);    // visit node
        inorder(root->right);           // traversal right subtree
    }
}

// 전위 순회 (preorder traversal)
void preorder(TreeNode* root) {
    if (root != NULL) {
        printf("[%d] ", root->data);    // visit node
        preorder(root->left);           // traversal left node
        preorder(root->right);          // traversal right node
    }
}

// 후위 순회 (postorder traversal)
void postorder(TreeNode* root) {
    if (root != NULL) {
        postorder(root->left);          // traversal left node
        postorder(root->right);         // traversal right node
        printf("[%d] ", root->data);    // visit node
    }
}