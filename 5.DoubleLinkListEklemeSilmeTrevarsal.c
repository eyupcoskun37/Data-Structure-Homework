#include <stdio.h>
#include <stdlib.h>

/* Node yapısı */
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

/* Başa ekleme */
struct Node* insertFront(struct Node *head, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    return newNode;
}

/* Sona ekleme */
struct Node* insertEnd(struct Node *head, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        return newNode;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

/* Araya ekleme (belirli bir değerden sonra) */
void insertAfter(struct Node *head, int after, int value) {
    struct Node *temp = head;

    while (temp != NULL && temp->data != after)
        temp = temp->next;

    if (temp == NULL) {
        printf("Eleman bulunamadi!\n");
        return;
    }

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

/* Silme (değere göre) */
struct Node* deleteNode(struct Node *head, int value) {
    struct Node *temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Silinecek eleman yok!\n");
        return head;
    }

    /* Head siliniyorsa */
    if (temp->prev == NULL) {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
    }
    else {
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }

    free(temp);
    return head;
}

/* Baştan sona traversal */
void traverseForward(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* Sondan başa traversal */
void traverseBackward(struct Node *head) {
    if (head == NULL) return;

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

/* MAIN */
int main() {
    struct Node *head = NULL;

    head = insertFront(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);

    printf("Forward: ");
    traverseForward(head);

    insertAfter(head, 20, 25);
    printf("After insert: ");
    traverseForward(head);

    head = deleteNode(head, 10);
    printf("After delete: ");
    traverseForward(head);

    printf("Backward: ");
    traverseBackward(head);

    return 0;
}
