#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

struct node {
  char data;
  struct node *left_child, *right_child;
};
typedef struct node *tree_pointer;

tree_pointer create_tree_node(char data);
void recursive_inorder(tree_pointer ptr);
void iter_inorder(tree_pointer ptr);
void iter_postorder(tree_pointer ptr);
void iter_preorder(tree_pointer ptr);
void level_order(tree_pointer ptr);

tree_pointer stack[MAX_STACK_SIZE];
int top = -1;

void push(tree_pointer* stack, tree_pointer node) {
    if (top <= MAX_STACK_SIZE - 1)
        stack[++top] = node;
}

int is_empty(tree_pointer* stack);

tree_pointer pop(tree_pointer* stack) {
    if (!is_empty(stack))
        return stack[top--];
    else return NULL;
}

tree_pointer peek(tree_pointer* stack) {
  return stack[top];
}
int is_empty(tree_pointer* stack) {
    return (top == -1);
}

tree_pointer queue[MAX_STACK_SIZE];
int front, rear;

void init_queue() {
  front = rear = 0;
}

int is_fullq() {
  return (rear + 1) % MAX_STACK_SIZE == front;
}

int is_emptyq() {
  return rear == front;
}

void enqueue(tree_pointer* queue, tree_pointer node) {
  if (!is_fullq()) {
    rear = (rear + 1) % MAX_STACK_SIZE;
    queue[rear] = node;
  }
}

tree_pointer dequeue(tree_pointer* queue) {
  if (!is_emptyq()) {
    front = (front + 1) % MAX_STACK_SIZE;
    return queue[front];
  }
}

/* TODO: add function prototype if necessary */

void main() {

  /* create a tree that represents an arithmetic expression */
  tree_pointer ptr, ptr1, ptr2;

  //        /
  //     A     B
  ptr1 = create_tree_node('A');
  ptr2 = create_tree_node('B');
  ptr = create_tree_node('/');
  ptr->left_child = ptr1;
  ptr->right_child = ptr2;

  //      *
  //    /   C
  //  A  B
  ptr1 = ptr;
  ptr2 = create_tree_node('C');
  ptr = create_tree_node('*');
  ptr->left_child = ptr1;
  ptr->right_child = ptr2;

  //        *
  //      *   D
  //    /   C
  //  A  B
  ptr1 = ptr;
  ptr2 = create_tree_node('D');
  ptr = create_tree_node('*');
  ptr->left_child = ptr1;
  ptr->right_child = ptr2;

  //         +
  //       *  E
  //     *  D
  //   /  C
  // A  B
  ptr1 = ptr;
  ptr2 = create_tree_node('E');
  ptr = create_tree_node('+');
  ptr->left_child = ptr1;
  ptr->right_child = ptr2;

  /* call traversal functions */
  //recursive_inorder(ptr);
  //printf("\n");
  //iter_inorder(ptr);
  //printf("\n");
  //iter_preorder(ptr);
  //printf("\n");
  iter_postorder(ptr);
  printf("\n");
  level_order(ptr);
  printf("\n");
}
  
tree_pointer create_tree_node(char data) {
  tree_pointer ptr = (tree_pointer)malloc(sizeof(struct node));
  ptr->data = data;
  ptr->left_child = NULL;
  ptr->right_child = NULL;
  return ptr;
}

void recursive_inorder(tree_pointer ptr) {
  if(ptr) {
    recursive_inorder(ptr->left_child);
    printf("%c ", ptr->data);
    recursive_inorder(ptr->right_child);
  }
}

void iter_inorder(tree_pointer ptr) {
    while (1) {
        for (; ptr; ptr = ptr->left_child) push(stack, ptr);
        ptr = pop(stack);
        if (ptr == NULL) break;
        printf("%c ", ptr->data);
        ptr = ptr->right_child;
    }
}

void iter_preorder(tree_pointer ptr) {
    while (1) {
        for (; ptr; ptr = ptr->left_child) {
          printf("%c ", ptr->data);
          push(stack, ptr);
        }
        ptr = pop(stack);
        if (ptr == NULL) break;
        ptr = ptr->right_child;
    }
}
void iter_postorder(tree_pointer ptr) {
    while (1) {
      for (; ptr; ptr = ptr->left_child) {
        push(stack, ptr);
        push(stack, ptr);
        //printf("%c가 stack에 2개 저장되었다.\n", ptr->data);
      }
      ptr = pop(stack);
      //printf("%c가 stack에서 삭제되었다.\n", ptr->data);
      if (!is_empty(stack)) {
        if (ptr == peek(stack)) {
          ptr = ptr->right_child;
        }
        else {
          printf("%c ", ptr->data);
          ptr = NULL;
        }
      }
      else {
        break;
      }
    }
    printf("%c ", ptr->data);
}
void level_order(tree_pointer ptr) {
  init_queue();
  if (ptr == NULL) return;
  enqueue(queue, ptr);
  while (!is_emptyq()) {
    ptr = dequeue(queue);
    if (ptr == NULL) break;
    printf("%c ", ptr->data);
    if (ptr->left_child) enqueue(queue, ptr->left_child);
    if (ptr->right_child) enqueue(queue, ptr->right_child);
  }
}

/* TODO: add function implementations here */