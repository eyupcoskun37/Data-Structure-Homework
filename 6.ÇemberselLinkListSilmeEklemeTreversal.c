#include <stdio.h>
#include <stdlib.h>

/* Node tanımı */
struct Node {
    int data;
    struct Node *next;
};

/* Traversal (gezme) */
void traverse(struct Node *head) {
    if (head == NULL) {
        printf("Liste bos\n");
        return;
    }

    struct Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

/* Sona ekleme */
struct Node* insertEnd(struct Node *head, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    struct Node *temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;

    return head;
}

/* Araya ekleme (belirli bir değerden sonra) */
void insertAfter(struct Node *head, int after, int value) {
    if (head == NULL) return;

    struct Node *temp = head;
    do {
        if (temp->data == after) {
            struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Eleman bulunamadi!\n");
}

/* Silme (değere göre) */
struct Node* deleteNode(struct Node *head, int value) {
    if (head == NULL) return NULL;

    struct Node *curr = head;
    struct Node *prev = NULL;

    /* Tek eleman varsa */
    if (head->data == value && head->next == head) {
        free(head);
        return NULL;
    }

    do {
        if (curr->data == value) {
            if (curr == head) {
                /* Head siliniyorsa */
                struct Node *temp = head;
                while (temp->next != head)
                    temp = temp->next;

                head = head->next;
                temp->next = head;
                free(curr);
            } else {
                prev->next = curr->next;
                free(curr);
            }
            return head;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);

    printf("Silinecek eleman yok!\n");
    return head;
}

/* MAIN */
int main() {
    struct Node *head = NULL;

    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);

    printf("Liste: ");
    traverse(head);

    insertAfter(head, 20, 25);
    printf("Araya ekleme sonrasi: ");
    traverse(head);

    head = deleteNode(head, 10);
    printf("Silme sonrasi: ");
    traverse(head);

    return 0;
}
