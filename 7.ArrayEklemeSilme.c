#include <stdio.h>

#define MAX 100

/* Diziyi yazdırma */
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* Başa ekleme */
int insertFront(int arr[], int n, int value) {
    for (int i = n; i > 0; i--)
        arr[i] = arr[i - 1];

    arr[0] = value;
    return n + 1;
}

/* Araya ekleme (index'e) */
int insertAt(int arr[], int n, int index, int value) {
    for (int i = n; i > index; i--)
        arr[i] = arr[i - 1];

    arr[index] = value;
    return n + 1;
}

/* Sona ekleme */
int insertEnd(int arr[], int n, int value) {
    arr[n] = value;
    return n + 1;
}

/* Baştan silme */
int deleteFront(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];

    return n - 1;
}

/* Aradan silme (index'ten) */
int deleteAt(int arr[], int n, int index) {
    for (int i = index; i < n - 1; i++)
        arr[i] = arr[i + 1];

    return n - 1;
}

/* Sondan silme */
int deleteEnd(int n) {
    return n - 1;
}

/* MAIN */
int main() {
    int arr[MAX] = {10, 20, 30, 40};
    int n = 4;

    printf("Baslangic: ");
    printArray(arr, n);

    n = insertFront(arr, n, 5);
    printf("Basa ekleme: ");
    printArray(arr, n);

    n = insertAt(arr, n, 2, 15);
    printf("Araya ekleme: ");
    printArray(arr, n);

    n = insertEnd(arr, n, 50);
    printf("Sona ekleme: ");
    printArray(arr, n);

    n = deleteFront(arr, n);
    printf("Bastan silme: ");
    printArray(arr, n);

    n = deleteAt(arr, n, 2);
    printf("Aradan silme: ");
    printArray(arr, n);

    n = deleteEnd(n);
    printf("Sondan silme: ");
    printArray(arr, n);

    return 0;
}
