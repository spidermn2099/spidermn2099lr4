#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void initializeSquare(int square[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            square[i][j] = 0; // Инициализация массива
        }
    }
}

void fillMagicSquare(int square[MAX_SIZE][MAX_SIZE], int n) {
    int i = 0, j = n / 2; // Стартовая позиция

    for (int num = 1; num <= n * n; num++) {
        square[i][j] = num; // Заполняем текущее место

        // Переходим к следующей позиции
        int new_i = (i - 1 + n) % n; // Вверх
        int new_j = (j + 1) % n; // Вправо

        if (square[new_i][new_j] != 0) { // Если клетка занята,
            i = (i + 1) % n; // Переход вниз
        } else {
            i = new_i;
            j = new_j;
        }
    }
}

void printSquare(int square[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%2d ", square[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the order of magic square (odd): ");
    scanf("%d", &n);

    if (n % 2 == 0 || n <= 0 || n > MAX_SIZE) {
        printf("Please enter a valid odd positive integer less than or equal to %d.\n", MAX_SIZE);
        return 1; // Ошибка
    }

    int square[MAX_SIZE][MAX_SIZE];
    initializeSquare(square, n);
    fillMagicSquare(square, n);
    printSquare(square, n);

    return 0;
}