#include <stdio.h>
#include <stdlib.h>

// 스택의 노드 구조체 정의 (연결리스트 기반)
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 스택 구조체: 맨 위(top) 노드를 가리키는 포인터 관리
typedef struct Stack {
    Node* top;
} Stack;

// 함수 프로토타입 선언
void init_stack(Stack* s);
void push(Stack* s, int data);
int pop(Stack* s);
int peek(Stack* s);
void print_stack(Stack* s);
void free_stack(Stack* s);

int main() {
    Stack s;
    init_stack(&s); // 스택 초기화

    // [시나리오 1] push(1), push(2), push(3) 후 전체 출력
    printf("1. 스택에 1, 2, 3 차례대로 Push\n");
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    print_stack(&s);

    // [시나리오 2] pop() 두 번 후 전체 출력
    printf("\n2. Pop 연산 2번 수행\n");
    printf("Pop 된 값: %d\n", pop(&s));
    printf("Pop 된 값: %d\n", pop(&s));
    print_stack(&s);

    // 현재 top 값 확인 (peek)
    printf("\n현재 Stack의 Top 값 (peek): %d\n", peek(&s));

    // [시나리오 3] 빈 스택을 만들고 pop() 했을 때 예외 처리 확인
    printf("\n3. 남은 원소 Pop 후 빈 스택에서 Pop 시도\n");
    pop(&s); // 마지막 남은 1 제거 (이제 스택은 비어있음)
    pop(&s); // 빈 스택에서 pop 시도 (예외 처리 발동)

    // 프로그램 종료 전 메모리 해제
    free_stack(&s);

    return 0;
}

// 스택 초기화 함수
void init_stack(Stack* s) {
    s->top = NULL;
}

// push: 스택의 맨 위에 데이터 추가
void push(Stack* s, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return;
    
    newNode->data = data;
    newNode->next = s->top; // 새 노드가 기존의 top 노드를 가리키게 함
    s->top = newNode;       // 스택의 top을 새 노드로 업데이트
}

// pop: 스택에서 가장 위에 있는 데이터를 꺼내고 메모리 해제
int pop(Stack* s) {
    // [과제 조건] 빈 스택 예외 처리
    if (s->top == NULL) {
        printf("[Error] Stack Underflow! 스택이 비어있어 데이터를 꺼낼 수 없습니다.\n");
        return -1; // 에러 코드 반환
    }

    Node* temp = s->top;   // 꺼낼 노드 저장
    int popped_data = temp->data;

    s->top = temp->next;   // top을 다음 노드로 이동
    free(temp);            // 메모리 해제

    return popped_data;
}

// peek: top이 가리키는 노드의 값만 확인 (제거 안 함)
int peek(Stack* s) {
    if (s->top == NULL) {
        printf("[Warning] 스택이 비어있습니다.\n");
        return -1;
    }
    return s->top->data;
}

// print_stack: 현재 스택의 모든 원소를 상단(top)부터 출력
void print_stack(Stack* s) {
    Node* current = s->top;
    if (current == NULL) {
        printf("현재 스택이 비어있습니다.\n");
        return;
    }

    printf("--- 현재 스택 상태 (Top -> Bottom) ---\n");
    while (current != NULL) {
        if (current == s->top) {
            printf("[Top] %d\n", current->data);
        } else {
            printf("      %d\n", current->data);
        }
        current = current->next;
    }
    printf("--------------------------------------\n");
}

// free_stack: 스택에 남아있는 모든 메모리 해제
void free_stack(Stack* s) {
    Node* current = s->top;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    s->top = NULL;
}