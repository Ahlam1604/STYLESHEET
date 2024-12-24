#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* nextNode;
};

struct Node* head = NULL;

void createList();
void frontInsertion(int value);
void middleInsertion(int value, int position);
void backInsertion(int value);
void frontDeletion();
void middleDeletion(int position);
void backDeletion();
void displayList();

int main() {
    int choice, value, position;

    while (1) {
        printf("\nOperations on Single Linked List:\n");
        printf("1. Create List\n");
        printf("2. Front Insertion\n");
        printf("3. Middle Insertion\n");
        printf("4. Back Insertion\n");
        printf("5. Front Deletion\n");
        printf("6. Middle Deletion\n");
        printf("7. Back Deletion\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createList();
                break;
            case 2:
                printf("Enter value to insert at the front: ");
                scanf("%d", &value);
                frontInsertion(value);
                break;
            case 3:
                printf("Enter value to insert in the middle: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                middleInsertion(value, position);
                break;
            case 4:
                printf("Enter value to insert at the back: ");
                scanf("%d", &value);
                backInsertion(value);
                break;
            case 5:
                frontDeletion();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                middleDeletion(position);
                break;
            case 7:
                backDeletion();
                break;
            case 8:
                displayList();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }
}

void createList() {
    int value;
    struct Node* newNode;
    printf("Enter value for the first node: ");
    scanf("%d", &value);

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->nextNode = NULL;
    head = newNode;
}

void frontInsertion(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->nextNode = head;
    head = newNode;
}

void middleInsertion(int value, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    int i;

    newNode->data = value;

    for (i = 1; i < position - 1; i++) {
        temp = temp->nextNode;
        if (temp == NULL) {
            printf("Position out of range\n");
            return;
        }
    }

    newNode->nextNode = temp->nextNode;
    temp->nextNode = newNode;
}

void backInsertion(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;

    newNode->data = value;
    newNode->nextNode = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        while (temp->nextNode != NULL) {
            temp = temp->nextNode;
        }
        temp->nextNode = newNode;
    }
}

void frontDeletion() {
    struct Node* temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    head = head->nextNode;
    free(temp);
}

void middleDeletion(int position) {
    struct Node* temp = head;
    struct Node* temp2;
    int i;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (position == 1) {
        frontDeletion();
        return;
    }

    for (i = 1; i < position - 1; i++) {
        temp = temp->nextNode;
        if (temp == NULL || temp->nextNode == NULL) {
            printf("Position out of range\n");
            return;
        }
    }

    temp2 = temp->nextNode;
    temp->nextNode = temp2->nextNode;
    free(temp2);
}

void backDeletion() {
    struct Node* temp = head;
    struct Node* prev;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->nextNode == NULL) { // If there's only one element
        free(head);
        head = NULL;
        return;
    }

    while (temp->nextNode != NULL) {
        prev = temp;
        temp = temp->nextNode;
    }

    prev->nextNode = NULL;
    free(temp);
}

void displayList() {
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->nextNode;
    }
    printf("NULL\n");
}
