#include <stdio.h>

void buyukKucukSiralama(int arr[], int n) {
    int temp, i, j;

    for (i = 0; i < n / 2; i++) {

        for (j = i; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

        for (j = n - 2 - i; j > i; j--) {
            if (arr[j] > arr[j - 1]) {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

int main() {
    int X[] = {60, 80, 3, 9, 57, 11};
    int n = sizeof(X) / sizeof(X[0]);

    buyukKucukSiralama(X, n);

    printf("Sıralanmış dizi: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", X[i]);
    }
    printf("\n");

    return 0;
}