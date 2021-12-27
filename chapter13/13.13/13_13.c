Tree23Node* tree23_search(Tree23Node* root, int key)
{
    if (root == NULL)                   // if the tree is empty
        return FALSE;
    else if (key == root->data)         // if key of the root and the key are eqaul
        return TRUE;
    else if (root->type == TWO_NODE) {  // 2-node
        if (key < root->key)
            return tree23_search(root->left, key);
        else
            return tree23_search(root->right, key);
    }
    else {
    // 3-node
        if (key < root->key1)
            return tree23_search(root->left, key);
        else if (key > root->key2)
            return tree23_search(root->right, key);
        else
            return tree23_search(root->middle, key);
    }
}