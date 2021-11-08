// English dictionary using binary search tree
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAX_WORD_SIZE 100
#define MAX_MEANING_SIZE 200

// data type
typedef struct {        // key field
    char word[MAX_WORD_SIZE];
    char meaning[MAX_MEANING_SIZE];
} element;

// structure of node
typedef struct TreeNode {
    element key;
    struct TreeNode *left, *right;
} TreeNode;

// if e1 < e2 then return -1
// if e1 == e2 then return 0
// if e1 > e2 then return 1
int compare(element e1, element e2)
{
    return strcmp(e1.word, e2.word);
}

// binary search tree displaying function
void display(TreeNode* p)
{
    if (p != NULL) {
        putchar('(');
        display(p->left);
        printf(" %s : %s ", p->key.word, p->key.meaning);
        display(p->right);
        putchar(')');
    }
}

// binary search tree searching function
TreeNode* search(TreeNode* root, element key)
{
    TreeNode* p = root;
    while (p != NULL) {
        if (compare(key, p->key) == 0)
            return p;
        else if (compare(key, p->key) < 0)
            p = p->left;
        else
            p = p->right;
    }
    return p;   // if failed searching then return NULL
}

TreeNode* new_node(element item)
{
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode* insert_node(TreeNode* node, element key)
{
    // if tree is empty then return new node
    if (node == NULL) return new_node(key);

    // if it isn't then recursively go down the tree
    if (compare(key, node->key) < 0)
        node->left = insert_node(node->left, key);
    else if (compare(key, node->key) > 0)
        node->right = insert_node(node->right, key);
    // return root pointer
    return node;
}

TreeNode* min_value_node(TreeNode* node)
{
    TreeNode* current = node;
    // go down to find very left node
    while (current->left != NULL)
        current = current->left;
    return current;
}

// if binary search tree and key are given, delete a node which contains key and return new root node
TreeNode* delete_node(TreeNode* root, element key)
{
    if (root == NULL) return root;
    // if the key is smaller than the root's key, then it is in the left subtree
    if (compare(key, root->key) < 0)
        root->left = delete_node(root->left, key);
    // if the key is bigger than the root's key, then it is in the right subtree
    if (compare(key, root->key) > 0)
        root->right = delete_node(root->right, key);
    // if the key is the same as the root's key, then delete this node
    else {
        // first or second case
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        // thrid case
        TreeNode* temp = min_value_node(root->right);

        // copy successor node during the inorder traversal
        root->key = temp->key;
        // delete successor node during the inorder traversal
        root->right = delete_node(root->right, temp->key);
    }
    return root;
}

//
void help()
{
    printf("\n**** i : 입력 | d : 삭제 | s : 탐색 | p : 출력 | q : 종료 **** : ");
}

// English dictionary program which uses binary search tree
int main(void)
{
    char command;
    element e;
    TreeNode* root = NULL;
    TreeNode* tmp;

    do {
        help();
        command = getchar();
        getchar();      // remove '\n'
        switch (command) {
        case 'i' :
            printf("단어 : ");
            gets(e.word);
            printf("의미 : ");
            gets(e.meaning);
            root = insert_node(root, e);
            break;
        case 'd' :
            printf("단어 : ");
            gets(e.word);
            root = delete_node(root, e);
            break;
        case 'p' :
            display(root);
            putchar('\n');
            break;
        case 's' :
            printf("단어 : ");
            gets(e.word);
            tmp = search(root, e);
            if (tmp)
                printf("의미 : %s\n", e.meaning);
            break;
        }
    } while (command != 'q');
    return 0;
}