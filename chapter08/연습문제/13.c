#define TRUE 1
#define FALSE 0
#define max(A, B) (A > B) ? A : B

int getHeight(TreeNode* root)
{
    if (root == NULL) return 0;
    else return max(getHeight(root->left), getHeight(root->right)) + 1;
}
int isBalanced(TreeNode* root)
{
    if (root == NULL) return TRUE;
    int dif = getHeight(root->left) - getHeight(root->right);
    if (dif > 1 || dif < -1) return FALSE;
    else return TRUE;
}