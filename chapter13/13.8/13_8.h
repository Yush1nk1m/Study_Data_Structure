// right rotate function
AVLNode* rotate_right(AVLNode* parent)
{
    AVLNode* child = parent->left;
    parent->left = child->right;
    child->right = parent;
    // return new node
    return child;
}