#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void birlestirmeliSiralama(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void secmeliSiralama(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n-1; i++) {
   
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int X[1000]; 
    int i, n = 500; 

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        X[i] = rand() % 1001; 
    }

    clock_t birlestirmeli_basla = clock();
    birlestirmeliSiralama(X, n);
    clock_t birlestirmeli_bitir = clock();
    double birlestirmeli_sure = (double)(birlestirmeli_bitir - birlestirmeli_basla) / CLOCKS_PER_SEC;

    clock_t secmeli_basla = clock();
    secmeliSiralama(X, n);
    clock_t secmeli_bitir = clock();
    double secmeli_sure = (double)(secmeli_bitir - secmeli_basla) / CLOCKS_PER_SEC;

    printf("Birleştirmeli Sıralama için geçen süre: %f s\n", birlestirmeli_sure);
    printf("Seçmeli Sıralama için geçen süre: %f s\n", secmeli_sure);

    return 0;
}