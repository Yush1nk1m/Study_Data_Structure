// 반복적인 탐색 함수
TreeNode* search(TreeNode* node, int key)
{
    while (node != NULL) {
        if (key == node->key) return node;
        else if (key < node->key)
            node = node->left;
        else
            node = node->right;
    }
    return NULL;    // 탐색에 실패했을 경우 NULL 반환
}