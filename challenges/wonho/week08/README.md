challenge 1  

```  
#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 노드 추가 함수
void append(Node** head, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));

    if (new_node == NULL) {
        printf("메모리 할당 실패\n");
        return;
    }

    new_node->data = data;
    new_node->next = NULL;

    printf("[append] 노드 생성\n");
    printf("주소: %p | data: %d | next: %p\n",
           (void*)new_node,
           new_node->data,
           (void*)new_node->next);

    // 첫 노드인 경우
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Node* current = *head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}

// 노드 삭제 함수
void delete(Node** head, int data) {
    Node* current = *head;
    Node* prev = NULL;

    // 첫 노드 삭제
    if (current != NULL && current->data == data) {
        *head = current->next;

        printf("[delete] 삭제 주소: %p\n", (void*)current);

        free(current);
        return;
    }

    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("삭제할 데이터 없음\n");
        return;
    }

    prev->next = current->next;

    printf("[delete] 삭제 주소: %p\n", (void*)current);

    free(current);
}

// 전체 출력 함수
void print_list(Node* head) {
    Node* current = head;

    printf("\n[연결리스트 출력]\n");

    while (current != NULL) {
        printf("노드 주소: %p | data: %d | next: %p\n",
               (void*)current,
               current->data,
               (void*)current->next);

        current = current->next;
    }

    printf("\n");
}

// 전체 메모리 해제
void free_list(Node* head) {
    Node* current = head;

    while (current != NULL) {
        Node* temp = current;

        current = current->next;

        printf("[free] 해제 주소: %p\n", (void*)temp);

        free(temp);
    }
}

int main() {
    Node* head = NULL;

    // 노드 5개 추가
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 50);

    // 전체 출력
    print_list(head);

    // 중간 노드 삭제
    delete(&head, 30);

    // 삭제 후 출력
    print_list(head);

    // 전체 메모리 해제
    free_list(head);

    return 0;
}
```
결과  
```
[append] 노드 생성
주소: 0x587c365f32a0 | data: 10 | next: (nil)
[append] 노드 생성
주소: 0x587c365f36d0 | data: 20 | next: (nil)
[append] 노드 생성
주소: 0x587c365f36f0 | data: 30 | next: (nil)
[append] 노드 생성
주소: 0x587c365f3710 | data: 40 | next: (nil)
[append] 노드 생성
주소: 0x587c365f3730 | data: 50 | next: (nil)

[연결리스트 출력]
노드 주소: 0x587c365f32a0 | data: 10 | next: 0x587c365f36d0
노드 주소: 0x587c365f36d0 | data: 20 | next: 0x587c365f36f0
노드 주소: 0x587c365f36f0 | data: 30 | next: 0x587c365f3710
노드 주소: 0x587c365f3710 | data: 40 | next: 0x587c365f3730
노드 주소: 0x587c365f3730 | data: 50 | next: (nil)

[delete] 삭제 주소: 0x587c365f36f0

[연결리스트 출력]
노드 주소: 0x587c365f32a0 | data: 10 | next: 0x587c365f36d0
노드 주소: 0x587c365f36d0 | data: 20 | next: 0x587c365f3710
노드 주소: 0x587c365f3710 | data: 40 | next: 0x587c365f3730
노드 주소: 0x587c365f3730 | data: 50 | next: (nil)

[free] 해제 주소: 0x587c365f32a0
[free] 해제 주소: 0x587c365f36d0
[free] 해제 주소: 0x587c365f3710
[free] 해제 주소: 0x587c365f3730
```
노드가 데이터와 다음 데이터 주소로 이루어져있어서 다음 노드에 어떤 값이 있는지 알 수 있다  

challenge 2  
```
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;

// push
void push(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));

    if (new_node == NULL) {
        printf("메모리 할당 실패\n");
        return;
    }

    new_node->data = data;
    new_node->next = top;

    top = new_node;

    printf("[push] %d 추가\n", data);
}

// pop
int pop() {
    if (top == NULL) {
        printf("[pop] 스택이 비어있음\n");
        return -1;
    }

    Node* temp = top;
    int value = temp->data;

    top = top->next;

    free(temp);

    printf("[pop] %d 제거\n", value);

    return value;
}

// peek
void peek() {
    if (top == NULL) {
        printf("[peek] 스택이 비어있음\n");
        return;
    }

    printf("[peek] top 값: %d\n", top->data);
}

// 전체 출력
void print_stack() {
    Node* current = top;

    printf("\n[스택 출력]\n");

    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }

    printf("\n");
}

// 전체 해제
void free_stack() {
    while (top != NULL) {
        pop();
    }
}

int main() {

    push(1);
    push(2);
    push(3);

    print_stack();

    peek();

    pop();
    pop();

    print_stack();

    // 빈 스택 pop 테스트
    pop();
    pop();

    free_stack();

    return 0;
}
```
결과  
```
[push] 1 추가
[push] 2 추가
[push] 3 추가

[스택 출력]
3
2
1

[peek] top 값: 3
[pop] 3 제거
[pop] 2 제거

[스택 출력]
1

[pop] 1 제거
[pop] 스택이 비어있음
```
스택은 선입후출을 원칙으로 하며 나중에 들어온 값이 먼저 나가게된다  
