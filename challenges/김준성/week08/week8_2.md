#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void push(Node** top, int data)
{
    Node* newNode = malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = *top;

    *top = newNode;
}

void pop(Node** top)
{
    if (*top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    Node* temp = *top;
    *top = (*top)->next;

    free(temp);
}

void peek(Node* top)
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Top: %d\n", top->data);
}

void print_stack(Node* top)
{
    Node* current = top;

    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

void free_stack(Node* top)
{
    Node* current = top;

    while (current != NULL)
    {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{
    Node* top = NULL;

    push(&top, 1);
    push(&top, 2);
    push(&top, 3);

    printf("push(1), push(2), push(3) 후:\n");
    print_stack(top);

    peek(top);

    pop(&top);
    pop(&top);

    printf("pop() 두 번 후:\n");
    print_stack(top);

    pop(&top);

    printf("빈 스택에서 pop() 실행:\n");
    pop(&top);

    free_stack(top);

    return 0;
}

push(1), push(2), push(3) 후:
3 -> 2 -> 1 -> NULL
Top: 3
pop() 두 번 후:
1 -> NULL
빈 스택에서 pop() 실행:
Stack is empty
