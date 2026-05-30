#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *top = NULL;

Node *create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));

    if (new_node == NULL) {
        printf("malloc failed\n");
        exit(1);
    }

    new_node->data = data;
    new_node->next = NULL;

    printf("[malloc] node data = %d, address = %p\n", data, (void *)new_node);

    return new_node;
}

void push(int data) {
    Node *new_node = create_node(data);

    new_node->next = top;
    top = new_node;

    printf("[push] data = %d, top = %p\n", data, (void *)top);
}

int pop(void) {
    if (top == NULL) {
        printf("[pop] stack is empty\n");
        return -1;
    }

    Node *temp = top;
    int value = temp->data;

    top = top->next;

    printf("[pop] data = %d, free address = %p\n", value, (void *)temp);
    free(temp);

    return value;
}

int peek(void) {
    if (top == NULL) {
        printf("[peek] stack is empty\n");
        return -1;
    }

    printf("[peek] top data = %d, top address = %p\n", top->data, (void *)top);
    return top->data;
}

void print_stack(void) {
    Node *cur = top;

    printf("Stack top -> ");

    while (cur != NULL) {
        printf("[%d | addr=%p | next=%p] -> ",
               cur->data, (void *)cur, (void *)cur->next);
        cur = cur->next;
    }

    printf("NULL\n");
}

void free_stack(void) {
    while (top != NULL) {
        Node *temp = top;
        top = top->next;

        printf("[free] node data = %d, address = %p\n", temp->data, (void *)temp);
        free(temp);
    }
}

int main(void) {
    printf("=== Push 1, 2, 3 ===\n");
    push(1);
    push(2);
    push(3);

    printf("\n=== Print stack after push ===\n");
    print_stack();

    printf("\n=== Peek top ===\n");
    peek();

    printf("\n=== Pop twice ===\n");
    pop();
    pop();

    printf("\n=== Print stack after pop twice ===\n");
    print_stack();

    printf("\n=== Pop remaining nodes ===\n");
    pop();

    printf("\n=== Pop from empty stack ===\n");
    pop();

    printf("\n=== Free stack ===\n");
    free_stack();

    return 0;
}