#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

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

void append(Node **head, int data) {
    Node *new_node = create_node(data);

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Node *cur = *head;

    while (cur->next != NULL) {
        cur = cur->next;
    }

    cur->next = new_node;
}

void delete_node(Node **head, int data) {
    if (*head == NULL) {
        printf("list is empty\n");
        return;
    }

    Node *cur = *head;
    Node *prev = NULL;

    if (cur->data == data) {
        *head = cur->next;
        printf("[free] delete node data = %d, address = %p\n", cur->data, (void *)cur);
        free(cur);
        return;
    }

    while (cur != NULL && cur->data != data) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) {
        printf("data %d not found\n", data);
        return;
    }

    prev->next = cur->next;
    printf("[free] delete node data = %d, address = %p\n", cur->data, (void *)cur);
    free(cur);
}

void print_list(Node *head) {
    Node *cur = head;

    printf("Linked List: ");

    while (cur != NULL) {
        printf("[%d | addr=%p | next=%p] -> ",
               cur->data, (void *)cur, (void *)cur->next);
        cur = cur->next;
    }

    printf("NULL\n");
}

void free_list(Node **head) {
    Node *cur = *head;

    while (cur != NULL) {
        Node *temp = cur;
        cur = cur->next;

        printf("[free] node data = %d, address = %p\n", temp->data, (void *)temp);
        free(temp);
    }

    *head = NULL;
}

int main(void) {
    Node *head = NULL;

    printf("=== Append 5 nodes ===\n");
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 50);

    printf("\n=== Print list after append ===\n");
    print_list(head);

    printf("\n=== Delete middle node: 30 ===\n");
    delete_node(&head, 30);

    printf("\n=== Print list after delete ===\n");
    print_list(head);

    printf("\n=== Free all nodes ===\n");
    free_list(&head);

    printf("\n=== Print list after free ===\n");
    print_list(head);

    return 0;
}