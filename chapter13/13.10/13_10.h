// return the height of the tree
int get_height(AVLNode* node)
{
    int height = 0;

    if (node != NULL)
        height = 1 + max(get_height(node->left), get_height(node->right));
    
    return height;
}

// return the balance factor of the node
int get_balance(AVLNode* node)
{
    if (node == NULL) return 0;

    return get_height(node->left) - get_height(node->right);
}