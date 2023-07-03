#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

struct LinkedList {
    Node* head;
};

typedef struct LinkedList LinkedList;

void insertAtFront(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
}

void insertAtLast(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void insertAfter(LinkedList* list, int key, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (list->head == NULL) {
        printf("Error: Linked List is empty.\n");
        return;
    }

    Node* current = list->head;
    while (current != NULL && current->data != key) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Error: Key not found in the Linked List.\n");
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void insertBefore(LinkedList* list, int key, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (list->head == NULL) {
        printf("Error: Linked List is empty.\n");
        return;
    }

    if (list->head->data == key) {
        newNode->next = list->head;
        list->head = newNode;
        return;
    }

    Node* current = list->head;
    while (current->next != NULL && current->next->data != key) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Error: Key not found in the Linked List.\n");
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void removeFromList(LinkedList* list, int key) {
    if (list->head == NULL) {
        printf("Error: Linked List is empty.\n");
        return;
    }

    Node* current = list->head;
    Node* prev = NULL;

    if (current->data == key) {
        list->head = current->next;
        free(current);
        printf("Element with key %d removed from the list.\n", key);
        return;
    }

    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Error: Key not found in the Linked List.\n");
        return;
    }

    prev->next = current->next;
    free(current);
    printf("Element with key %d removed from the list.\n", key);
}

void displayList(LinkedList* list) {
    Node* current = list->head;
    if (current == NULL) {
        printf("Linked List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    LinkedList list;
    list.head = NULL;

    int choice, data, key;
    while (1) {
        printf("1. Insert at Front\n");
        printf("2. Insert at Last\n");
        printf("3. Insert After an Item\n");
        printf("4. Insert Before an Item\n");
        printf("5. Remove an Item\n");
        printf("6. Display List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertAtFront(&list, data);
                printf("Element inserted at the front.\n");
                break;
            case 2:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertAtLast(&list, data);
                printf("Element inserted at the last.\n");
                break;
            case 3:
                printf("Enter the key after which to insert: ");
                scanf("%d", &key);
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertAfter(&list, key, data);
                break;
            case 4:
                printf("Enter the key before which to insert: ");
                scanf("%d", &key);
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertBefore(&list, key, data);
                break;
            case 5:
                printf("Enter the key to remove: ");
                scanf("%d", &key);
                removeFromList(&list, key);
                break;
            case 6:
                displayList(&list);
                break;
            case 7:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    }

    return 0;
}