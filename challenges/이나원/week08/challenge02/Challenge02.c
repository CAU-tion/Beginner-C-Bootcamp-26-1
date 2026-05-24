#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;


Node* top = NULL;


void push(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = top;
    top = new_node;
}


int pop(void) {
    if (top == NULL) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    Node* tmp = top;
    int value = tmp->data;
    top = top->next;
    free(tmp);
    return value;
}


int peek(void) {
    if (top == NULL) {
        printf("Stack is empty. Nothing to peek.\n");
        return -1;
    }
    return top->data;
}


void print_stack(void) {
    Node* cur = top;
    printf("top -> ");
    while (cur != NULL) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

void free_stack(void) {
    while (top != NULL) {
        Node* next = top->next;
        free(top);
        top = next;
    }
}


int main(void) {
    char line[256];
    char cmd[32];
    int value;

    printf("Commands: push <n>, pop, peek, print, quit\n");

    while (1) {
        printf("> ");
        if (fgets(line, sizeof(line), stdin) == NULL)
            break;

        if (sscanf(line, "%31s", cmd) != 1)
            continue;

        if (strcmp(cmd, "push") == 0) {
            if (sscanf(line, "%*s %d", &value) == 1) {
                push(value);
                printf("pushed %d\n", value);
            } else {
                printf("Usage: push <number>\n");
            }
        }
        else if (strcmp(cmd, "pop") == 0) {
            int v = pop();
            if (v != -1)
                printf("popped %d\n", v);
        }
        else if (strcmp(cmd, "peek") == 0) {
            int v = peek();
            if (v != -1)
                printf("top is %d\n", v);
        }
        else if (strcmp(cmd, "print") == 0) {
            print_stack();
        }
        else if (strcmp(cmd, "quit") == 0) {
            break;
        }
        else {
            printf("Unknown command: %s\n", cmd);
        }
    }

    free_stack();
    return 0;
}