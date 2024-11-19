#include <iostream>
#include <vector>
#include <limits>

void displayMenu() {
    std::cout << "Лабораторная работа No4" << std::endl;
    std::cout << "Выполнил: Ганиев Абубакр" << std::endl;
    std::cout << "Группа: 453505" << std::endl;
    std::cout << "Вариант 6" << std::endl;
    std::cout << "Задание: Определить индексы всех седловых точек в матрице NxM." << std::endl;
    std::cout << "===========================================" << std::endl;
}

void findSaddlePoints(int** matrix, int rows, int cols) {
    std::cout << "Седловые точки (индексы):" << std::endl;
    bool hasSaddlePoint = false;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int element = matrix[i][j];
            bool isMinInRow = true, isMaxInCol = true;
            bool isMaxInRow = true, isMinInCol = true;

            for (int k = 0; k < cols; k++) {
                if (matrix[i][k] < element) {
                    isMinInRow = false;
                    break;
                }
            }

            for (int k = 0; k < rows; k++) {
                if (matrix[k][j] > element) {
                    isMaxInCol = false;
                    break;
                }
            }

            for (int k = 0; k < cols; k++) {
                if (matrix[i][k] > element) {
                    isMaxInRow = false;
                    break;
                }
            }

            
            for (int k = 0; k < rows; k++) {
                if (matrix[k][j] < element) {
                    isMinInCol = false;
                    break;
                }
            }

            
            if ((isMinInRow && isMaxInCol) || (isMaxInRow && isMinInCol)) {
                std::cout << "Седловая точка найдена на позиции: (" << i << ", " << j << ") со значением " << element << std::endl;
                hasSaddlePoint = true;
            }
        }
    }

    if (!hasSaddlePoint) {
        std::cout << "Седловые точки не найдены." << std::endl;
    }
}

int main() {
    displayMenu();

    int rows, cols;
    std::cout << "Введите количество строк (N): ";
    std::cin >> rows;
    std::cout << "Введите количество столбцов (M): ";
    std::cin >> cols;

    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    std::cout << "Введите элементы матрицы:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> matrix[i][j];
        }
    }

    findSaddlePoints(matrix, rows, cols);

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}