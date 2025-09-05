#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}


void insertBeginning(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Inserted %d at beginning\n", data);
}


void insertEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        printf("Inserted %d at beginning (list was empty)\n", data);
        return;
    }
    
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    printf("Inserted %d at end\n", data);
}


void insertAnywhere(int data, int pos) {
    if (pos == 1) {
        insertBeginning(data);
        return;
    }
    
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }
    
    newNode->next = temp->next;
    newNode->prev = temp;
    
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    
    printf("Inserted %d at position %d\n", data, pos);
}


void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct Node* temp = head;
    int data = temp->data;
    
    if (head->next == NULL) {
        head = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    
    free(temp);
    printf("Deleted %d from beginning\n", data);
}


void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct Node* temp = head;
    

    if (temp->next == NULL) {
        int data = temp->data;
        head = NULL;
        free(temp);
        printf("Deleted %d from end\n", data);
        return;
    }
    

    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    int data = temp->data;
    temp->prev->next = NULL;
    free(temp);
    printf("Deleted %d from end\n", data);
}


void deleteAnywhere(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    if (pos == 1) {
        deleteBeginning();
        return;
    }
    
    struct Node* temp = head;
    
    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    
    int data = temp->data;
    
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    
    temp->prev->next = temp->next;
    free(temp);
    
    printf("Deleted %d from position %d\n", data, pos);
}


void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    printf("List: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" <-> ");
        }
        temp = temp->next;
    }
    printf("\n");
}


void showMenu() {
    printf("\n===== DOUBLY LINKED LIST =====\n");
    printf("1. Insert at Beginning\n");
    printf("2. Insert at End\n");
    printf("3. Insert at Position\n");
    printf("4. Delete from Beginning\n");
    printf("5. Delete from End\n");
    printf("6. Delete from Position\n");
    printf("7. Display List\n");
    printf("8. Exit\n");
    printf("===============================\n");
    printf("Enter choice: ");
}

int main() {
    int choice, data, pos;
    
    while (1) {
        showMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertBeginning(data);
                break;
                
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertEnd(data);
                break;
                
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAnywhere(data, pos);
                break;
                
            case 4:
                deleteBeginning();
                break;
                
            case 5:
                deleteEnd();
                break;
                
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAnywhere(pos);
                break;
                
            case 7:
                display();
                break;
                
            case 8:
                printf("Exiting...\n");
                exit(0);
                
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}