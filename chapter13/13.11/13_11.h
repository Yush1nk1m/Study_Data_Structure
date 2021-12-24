// function which insert new node into AVL tree
// return the new node
AVLNode* insert(AVLNode* node, int key)
{
    // insert node of binary search tree
    if (node == NULL)
        return create_node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else    // the same key is not allowed
        return node;
    
    // recalculate balance factor of the nodes
    int balance = get_balance(node);

    // LL type process
    if (balance > 1 && key < node->left->key)
        return rotate_right(node);
    
    // RR type process
    if (balance < -1 && key > node->right->key)
        return rotate_left(node);
    
    // LR type process
    if (balance > 1 && key > node->left->key)
    {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }

    // RL type process
    if (balance < -1 && key < node->right->key)
    {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }

    return node;
}