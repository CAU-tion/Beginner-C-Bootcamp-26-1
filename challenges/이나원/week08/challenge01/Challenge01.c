#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;            // data field
    struct Node* next;   // pointer that pointing next node
} Node;


void append(Node** head, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));

    new_node->data = data;  
    new_node->next = NULL;  

    if (*head == NULL)
        *head = new_node;
    else {
        Node* cur = *head;          
        while (cur->next != NULL)   
            cur = cur->next;
        cur->next = new_node;     
    }
}


void delete(Node** head, int target) {
    if (*head == NULL)
        return;

    if ((*head)->data == target) {
        Node* tmp = *head;       
        *head = (*head)->next;    
        free(tmp);                
        return;
    }

    Node* prev = *head;
    Node* cur = (*head)->next;
    while (cur != NULL) {
        if (cur->data == target) {
            prev->next = cur->next;
            free(cur);
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}


void print_list(Node* head) {
    Node* cur = head;          
    while (cur != NULL) {      
        printf("%d -> ", cur->data);
        cur = cur->next;       
    }
    printf("NULL\n");         
}


void free_list(Node** head) {
    Node* cur = *head;
    while (cur != NULL) {
        Node* next = cur->next;  
        free(cur);             
        cur = next;            
    }
    *head = NULL;               
}


int main(void) {
    Node* head = NULL;
    char line[256];

    printf("Enter values: ");
    fgets(line, sizeof(line), stdin);

    char* p = line;
    int value, consumed;
    while (sscanf(p, "%d%n", &value, &consumed) == 1) {
        append(&head, value);
        p += consumed;
    }
    printf("\nAfter append: ");
    print_list(head);

    int target;
    printf("\nEnter a value to delete: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &target);
    delete(&head, target);
    printf("After deleting %d: ", target);
    print_list(head);

    free_list(&head);

    return 0;
}