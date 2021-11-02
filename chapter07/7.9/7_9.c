#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct StackNode {
    element data;
    struct StackNode* link;
} StackNode;

typedef struct {
    StackNode* top;
} LinkedStackType;

// initialize function
void init(LinkedStackType* s)
{
    s->top = NULL;
}

// empty status detection function
int is_empty(LinkedStackType* s)
{
    return (s->top == NULL);
}

// full status detection function
int is_full(LinkedStackType* s)
{
    return 0;
}

// insert function
void push(LinkedStackType* s, element item)
{
    StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
    temp->data = item;
    temp->link = s->top;
    s->top = temp;
}

void print_stack(LinkedStackType* s)
{
    for (StackNode* p = s->top; p != NULL; p = p->link)
        printf("%d -> ", p->data);
    puts("NULL");
}

// delete function
element pop(LinkedStackType* s)
{
    if (is_empty(s)) {
        fprintf(stderr, "Stack is empty.\n");
        exit(1);
    }
    else {
        StackNode* temp = s->top;
        int data = temp->data;
        s->top = s->top->link;
        free(temp);
        return data;
    }
}

// peek function
element peek(LinkedStackType* s)
{
    if (is_empty(s)) {
        fprintf(stderr, "Stack is empty.\n");
        exit(1);
    }
    else {
        return s->top->data;
    }
}

// main function
int main(void)
{
    LinkedStackType s;
    init(&s);
    push(&s, 1); print_stack(&s);
    push(&s, 2); print_stack(&s);
    push(&s, 3); print_stack(&s);
    pop(&s); print_stack(&s);
    pop(&s); print_stack(&s);
    pop(&s); print_stack(&s);
    return 0;
}