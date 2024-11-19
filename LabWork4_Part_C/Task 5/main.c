/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

#define MAX_SIZE 100

void printField(char field[MAX_SIZE][MAX_SIZE], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c ", field[i][j]);
        }
        printf("\n");
    }
}

int countMines(char field[MAX_SIZE][MAX_SIZE], int x, int y, int n, int m) {
    int count = 0;
    // Проверка всех 8 соседей
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue; // Пропускаем саму ячейку
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (field[nx][ny] == '*') {
                    count++;
                }
            }
        }
    }
    return count;
}

void fillField(char field[MAX_SIZE][MAX_SIZE], int n, int m) {
    // Создаем новый массив для хранения заполненных значений
    char result[MAX_SIZE][MAX_SIZE];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == '*') {
                result[i][j] = '*'; // Бомба
            } else {
                int mineCount = countMines(field, i, j, n, m);
                result[i][j] = mineCount + '0'; // Преобразуем количество в символ
            }
        }
    }

    // Копируем значения обратно в исходное поле
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            field[i][j] = result[i][j];
        }
    }
}

int main() {
    int n, m;
    printf("Enter the dimensions of the field (n m): ");
    scanf("%d %d", &n, &m);

    char field[MAX_SIZE][MAX_SIZE];
    printf("Enter the field ('.' for empty and '*' for bomb):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &field[i][j]);
        }
    }

    fillField(field, n, m);
    printf("Filled field:\n");
    printField(field, n, m);

    return 0;
}