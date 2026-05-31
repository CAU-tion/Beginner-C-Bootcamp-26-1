#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));

    if (new_node == NULL) {
        printf("malloc failed\n");
        exit(1);
    }

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}

void append(Node **head, int data) {
    Node *new_node = create_node(data);

    if (*head == NULL) {
        *head = new_node;
        printf("append %d: first node created\n", data);
        return;
    }

    Node *cur = *head;

    while (cur->next != NULL) {
        cur = cur->next;
    }

    cur->next = new_node;
    new_node->prev = cur;

    printf("append %d: linked after %d\n", data, cur->data);
}

void print_forward_simple(Node *head) {
    Node *cur = head;

    printf("Forward order : ");

    while (cur != NULL) {
        printf("%d", cur->data);

        if (cur->next != NULL) {
            printf(" -> ");
        }

        cur = cur->next;
    }

    printf(" -> NULL\n");
}

void print_backward_simple(Node *head) {
    if (head == NULL) {
        printf("Backward order: NULL\n");
        return;
    }

    Node *cur = head;

    while (cur->next != NULL) {
        cur = cur->next;
    }

    printf("Backward order: ");

    while (cur != NULL) {
        printf("%d", cur->data);

        if (cur->prev != NULL) {
            printf(" -> ");
        }

        cur = cur->prev;
    }

    printf(" -> NULL\n");
}

void print_pointer_table(Node *head) {
    Node *cur = head;

    printf("\n[Pointer Table]\n");
    printf("DATA\tPREV DATA\tNEXT DATA\n");
    printf("--------------------------------\n");

    while (cur != NULL) {
        printf("%d\t", cur->data);

        if (cur->prev == NULL) {
            printf("NULL\t\t");
        } else {
            printf("%d\t\t", cur->prev->data);
        }

        if (cur->next == NULL) {
            printf("NULL\n");
        } else {
            printf("%d\n", cur->next->data);
        }

        cur = cur->next;
    }
}

void delete_node(Node **head, int data) {
    if (*head == NULL) {
        printf("list is empty\n");
        return;
    }

    Node *cur = *head;

    while (cur != NULL && cur->data != data) {
        cur = cur->next;
    }

    if (cur == NULL) {
        printf("data %d not found\n", data);
        return;
    }

    printf("\ndelete node: %d\n", cur->data);

    if (cur->prev != NULL) {
        cur->prev->next = cur->next;
    } else {
        *head = cur->next;
    }

    if (cur->next != NULL) {
        cur->next->prev = cur->prev;
    }

    free(cur);
}

void free_list(Node **head) {
    Node *cur = *head;

    printf("\nfree all nodes\n");

    while (cur != NULL) {
        Node *temp = cur;
        cur = cur->next;

        printf("free node: %d\n", temp->data);
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

    printf("\n=== List after append ===\n");
    print_forward_simple(head);
    print_backward_simple(head);
    print_pointer_table(head);

    delete_node(&head, 30);

    printf("\n=== List after deleting 30 ===\n");
    print_forward_simple(head);
    print_backward_simple(head);
    print_pointer_table(head);

    free_list(&head);

    printf("\n=== List after free ===\n");
    print_forward_simple(head);

    return 0;
}