#include <stdio.h>
#define MAX_SIZE 3

struct Queue {
    int array[MAX_SIZE];
    int frontIndex;
    int rearIndex;
} q = { .frontIndex = -1, .rearIndex = -1 };

void addItem(int value);
int removeItem();
void showQueue();

int main() {
    int option = 1, data;
    while (option) {
        printf("\nQUEUE MENU:\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. View Queue\n");
        printf("Choose an operation: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter value to add: ");
                scanf("%d", &data);
                addItem(data);
                break;

            case 2:
                data = removeItem();
                if (data != -1) {
                    printf("Removed value: %d\n", data);
                }
                break;

            case 3:
                showQueue();
                break;

            default:
                printf("Invalid option, try again.\n");
        }
        printf("\nDo you want to continue? (1 for Yes, 0 for No): ");
        scanf("%d", &option);
    }
    return 0;
}

void addItem(int value) {
    if (q.rearIndex >= MAX_SIZE - 1) {
        printf("Queue is full. Cannot add %d.\n", value);
    } else {
        if (q.frontIndex == -1) {
            q.frontIndex = 0;
        }
        q.rearIndex++;
        q.array[q.rearIndex] = value;
        printf("Added %d to the queue.\n", value);
    }
}

int removeItem() {
    if (q.frontIndex == -1 || q.frontIndex > q.rearIndex) {
        printf("Queue is empty. Nothing to remove.\n");
        return -1;
    } else {
        int removedValue = q.array[q.frontIndex];
        q.frontIndex++;
        if (q.frontIndex > q.rearIndex) {
            q.frontIndex = q.rearIndex = -1;
        }
        return removedValue;
    }
}

void showQueue() {
    if (q.frontIndex == -1 || q.frontIndex > q.rearIndex) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue contents: ");
        for (int i = q.frontIndex; i <= q.rearIndex; i++) {
            printf("%d ", q.array[i]);
        }
        printf("\n");
    }
}
