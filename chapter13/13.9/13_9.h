// rotate left function
AVLNode* rotate_left(AVLNode* parent)
{
    AVLNode* child = parent->right;
    parent->right = child->left;
    child->left = parent;
    // return new node
    return child;
}