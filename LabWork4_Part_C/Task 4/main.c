#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter size of the cube (n): ");
    scanf("%d", &n);

    // Создаем динамический трёхмерный массив
    int ***arr = (int ***)malloc(n * sizeof(int **));
    for (int i = 0; i < n; i++) {
        arr[i] = (int **)malloc(n * sizeof(int *));
        for (int j = 0; j < n; j++) {
            arr[i][j] = (int *)malloc(n * sizeof(int));
        }
    }

    // Заполняем массив
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++) {
                printf("Enter element [%d][%d][%d]: ", i, j, k);
                scanf("%d", &arr[i][j][k]);
            }

    long long sum1 = 0, sum2 = 0; // Для хранения сумм
    for (int i = 0; i < n; i++) {
        sum1 += arr[i][i][i]; // Основная диагональ
        sum2 += arr[i][i][n - 1 - i]; // Вторичная диагональ
    }

    if (sum1 > sum2) {
        printf("Main diagonal has the greatest sum: %lld\n", sum1);
    } else if (sum2 > sum1) {
        printf("Secondary diagonal has the greatest sum: %lld\n", sum2);
    } else {
        printf("Both diagonals have equal sum: %lld\n", sum1);
    }

    // Освобождаем память
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            free(arr[i][j]);
        }
        free(arr[i]);
    }
    free(arr);

    return 0;
}