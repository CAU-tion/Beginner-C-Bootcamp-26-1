#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 함수 프로토타입 선언
void append(Node** head, int data);
void deleteNode(Node** head, int key);
void printList(Node* head);
void freeList(Node* head);

int main() {
    Node* head = NULL; // 리스트의 시작점 초기화

    // [시나리오 1] 노드 5개 추가 후 전체 출력
    printf("1. 노드 5개 추가 (10, 20, 30, 40, 50)\n");
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 50);
    printList(head);

    // [시나리오 2] 중간 노드 1개 삭제 후 전체 출력 (예: 30 삭제)
    printf("\n2. 중간 노드 30 삭제\n");
    deleteNode(&head, 30);
    printList(head);

    // [시나리오 3] 프로그램 종료 전 모든 노드 해제
    printf("\n3. 모든 메모리 해제 및 프로그램 종료\n");
    freeList(head);
    head = NULL;

    return 0;
}

void append(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return;
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    if (temp == NULL) {
        printf("리스트가 비어있습니다.\n");
        return;
    }
    printf("--- 현재 연결리스트 상태 ---\n");
    while (temp != NULL) {
        printf("[Addr: %p] Data: %d -> Next: %p\n", (void*)temp, temp->data, (void*)temp->next);
        temp = temp->next;
    }
    printf("-----------------------------\n");
}

void deleteNode(Node** head, int key) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp == NULL) return;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("데이터 %d를 찾을 수 없습니다.\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}