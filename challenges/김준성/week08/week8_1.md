# Challenge1. 단순 연결리스트 구현

## 코드

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void append(Node** head, int data) {
    Node* newNode = malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* last = *head;

    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
}

void delete_node(Node** head, int data) {
    if (*head == NULL)
        return;

    if ((*head)->data == data) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node* current = *head;

    while (current->next != NULL && current->next->data != data)
        current = current->next;

    if (current->next == NULL)
        return;

    Node* temp = current->next;
    current->next = temp->next;
    free(temp);
}

void print_list(Node* head) {
    Node* current = head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

void free_list(Node* head) {
    Node* current = head;

    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;

    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    printf("노드 5개 추가 후:\n");
    print_list(head);

    delete_node(&head, 3);

    printf("중간 노드 3 삭제 후:\n");
    print_list(head);

    free_list(head);

    return 0;
}
```

## 실행 결과

### 노드 5개 추가 후

```text
노드 5개 추가 후:
1 -> 2 -> 3 -> 4 -> 5 -> NULL
```

### 중간 노드(3) 삭제 후

```text
중간 노드 3 삭제 후:
1 -> 2 -> 4 -> 5 -> NULL
```

## GDB 확인

### 노드 주소 및 next 포인터

```gdb
(gdb) p head
$4 = (Node *) 0x5555555592a0

(gdb) p *head
$5 = {data = 1, next = 0x5555555592c0}

(gdb) p *((*head)->next)
$8 = {data = 2, next = 0x5555555592e0}

(gdb) p *((*head)->next->next)
$9 = {data = 3, next = 0x555555559300}

(gdb) p *((*head)->next->next->next)
$11 = {data = 4, next = 0x555555559320}

(gdb) p *((*head)->next->next->next->next)
$12 = {data = 5, next = 0x0}
```

### 연결 구조

```text
0x5555555592a0 -> 0x5555555592c0
0x5555555592c0 -> 0x5555555592e0
0x5555555592e0 -> 0x555555559300
0x555555559300 -> 0x555555559320
0x555555559320 -> NULL
```

