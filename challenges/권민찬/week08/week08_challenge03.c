#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

void append(Node** head, int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) return;

    new_node->data = new_data;
    new_node->next = NULL;

    // 리스트가 비어있는 경우
    if (*head == NULL) {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }

    // 끝까지 탐색
    Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    // 양방향 연결
    last->next = new_node;
    new_node->prev = last;
}

void deleteNode(Node** head, int key) {
    if (*head == NULL) return;

    Node* curr = *head;

    // 삭제할 노드 탐색
    while (curr != NULL && curr->data != key)
        curr = curr->next;

    // 삭제할 값을 찾지 못한 경우
    if (curr == NULL) return;

    // 삭제할 노드가 헤드(첫 번째 노드)인 경우
    if (*head == curr) *head = curr->next;

    // 삭제할 노드가 마지막 요소가 아니라면, 그 다음 노드의 prev를 삭제할 노드의 이전 노드로 연결
    if (curr->next != NULL) curr->next->prev = curr->prev;

    // 삭제할 노드가 헤드가 아니라면, 그 이전 노드의 next를 삭제할 노드의 다음 노드로 연결
    if (curr->prev != NULL) curr->prev->next = curr->next;

    free(curr);
}

void print_forward(Node* head) {
    printf("(First -> Last): ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void print_backward(Node* head) {
    printf("(Last -> First): ");
    if (head == NULL) {
        printf("NULL\n");
        return;
    }

    // 1. 우선 맨 마지막 노드까지 이동
    Node* last = head;
    while (last->next != NULL)
        last = last->next;

    // 2. prev 포인터를 타고 역으로 거슬러 올라가며 출력
    while (last != NULL) {
        printf("%d -> ", last->data);
        last = last->prev;
    }

    printf("NULL\n");
}

void freeAll(Node** head) {
    Node* curr = *head;
    Node* next_node;
    while (curr != NULL) {
        next_node = curr->next;
        free(curr);
        curr = next_node;
    }

    *head = NULL;
}

int main() {
    Node* head = NULL;

    printf("노드 5개 추가 (10, 20, 30, 40, 50)\n");
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 50);

    print_forward(head);
    print_backward(head);

    printf("\n 중간 노드 (30) 삭제\n");
    deleteNode(&head, 30);

    print_forward(head);
    print_backward(head);

    freeAll(&head);

    return 0;
}