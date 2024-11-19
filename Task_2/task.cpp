#include <iostream>
#include <vector>
#include <limits>

const int M = 3;  // Количество строк
const int N = 3;  // Количество столбцов

// Функция для отображения контекстного меню
void displayMenu() {
    std::cout << "Лабораторная работа No4" << std::endl;
    std::cout << "Выполнил: Ганиев Абубакр" << std::endl;
    std::cout << "Группа: 453505" << std::endl;
    std::cout << "Вариант 6" << std::endl;
    std::cout << "Задание: Определить количество положительных элементов, расположенных ниже побочной диагонали матрицы." << std::endl;
    std::cout << "===========================================" << std::endl;
}

// Функция для подсчета положительных элементов ниже побочной диагонали
int countPositiveBelowSecondaryDiagonal(const std::vector<std::vector<int>>& arr) {
    int count = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            // Проверяем, находится ли элемент ниже побочной диагонали
            if (i + j > N - 1 && arr[i][j] > 0) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    std::vector<std::vector<int>> matrix = {
        { 1, -2, 3 },
        { 4, 5, -6 },
        { -7, 8, 9 }
    };
    int count;
    char choice;
    bool repeat = true;

    while (repeat) {
        // Вывод контекстного меню
        displayMenu();

        // Вывод исходной матрицы
        std::cout << "Исходная матрица:" << std::endl;
        for (const auto& row : matrix) {
            for (int element : row) {
                std::cout << element << " ";
            }
            std::cout << std::endl;
        }

        // Подсчет положительных элементов ниже побочной диагонали
        count = countPositiveBelowSecondaryDiagonal(matrix);

        // Вывод результата
        std::cout << "Количество положительных элементов ниже побочной диагонали: " << count << std::endl;

        // Спрашиваем, хочет ли пользователь повторить
        std::cout << "Хотите выполнить программу снова? (y/n): ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // очищаем буфер
        choice = std::cin.get();

        if (choice != 'y' && choice != 'Y') {
            repeat = false;
        }
    }

    return 0;
}