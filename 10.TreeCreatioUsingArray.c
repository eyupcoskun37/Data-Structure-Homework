#include <stdio.h>

#define MAX 100

/* Tree dizisi */
int tree[MAX];
int size = 0;

/* Tree'ye ekleme (level-order) */
void insert(int value) {
    if (size >= MAX) {
        printf("Tree dolu!\n");
        return;
    }
    tree[size++] = value;
}

/* Tree'yi array olarak yazdırma */
void printTree() {
    for (int i = 0; i < size; i++)
        printf("%d ", tree[i]);
    printf("\n");
}

/* Preorder Traversal */
void preorder(int i) {
    if (i >= size) return;

    printf("%d ", tree[i]);
    preorder(2*i + 1);
    preorder(2*i + 2);
}

/* Inorder Traversal */
void inorder(int i) {
    if (i >= size) return;

    inorder(2*i + 1);
    printf("%d ", tree[i]);
    inorder(2*i + 2);
}

/* Postorder Traversal */
void postorder(int i) {
    if (i >= size) return;

    postorder(2*i + 1);
    postorder(2*i + 2);
    printf("%d ", tree[i]);
}

/* MAIN */
int main() {

    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);

    printf("Tree (array): ");
    printTree();

    printf("Preorder : ");
    preorder(0);

    printf("\nInorder  : ");
    inorder(0);

    printf("\nPostorder: ");
    postorder(0);

    return 0;
}
