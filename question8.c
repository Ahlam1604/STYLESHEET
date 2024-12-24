#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* nextNode;
    struct Node* prevNode;
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
        printf("\nOperations on Doubly Linked List:\n");
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
    newNode->prevNode = NULL;
    head = newNode;
}

void frontInsertion(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prevNode = NULL;
    newNode->nextNode = head;

    if (head != NULL) {
        head->prevNode = newNode;
    }

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
    newNode->prevNode = temp;

    if (temp->nextNode != NULL) {
        temp->nextNode->prevNode = newNode;
    }
    temp->nextNode = newNode;
}

void backInsertion(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;

    newNode->data = value;
    newNode->nextNode = NULL;

    if (head == NULL) {
        newNode->prevNode = NULL;
        head = newNode;
    } else {
        while (temp->nextNode != NULL) {
            temp = temp->nextNode;
        }
        temp->nextNode = newNode;
        newNode->prevNode = temp;
    }
}

void frontDeletion() {
    struct Node* temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    head = head->nextNode;
    if (head != NULL) {
        head->prevNode = NULL;
    }
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

    for (i = 1; i < position - 1; i++) {
        temp = temp->nextNode;
        if (temp == NULL) {
            printf("Position out of range\n");
            return;
        }
    }

    temp2 = temp->nextNode;
    temp->nextNode = temp2->nextNode;
    if (temp2->nextNode != NULL) {
        temp2->nextNode->prevNode = temp;
    }
    free(temp2);
}

void backDeletion() {
    struct Node* temp = head;
    struct Node* prev;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp->nextNode != NULL) {
        prev = temp;
        temp = temp->nextNode;
    }

    // Remove the last node
    if (prev != NULL) {
        prev->nextNode = NULL;
    } else {
        // Only one node in the list
        head = NULL;
    }
    free(temp);
}

void displayList() {
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->nextNode;
    }
    printf("NULL\n");
}
