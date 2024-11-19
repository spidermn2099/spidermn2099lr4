#include <iostream>
#include <vector>
#include <limits>

// Функция для циклического сдвига массива влево
void cyclicShiftLeft(std::vector<int>& arr, int k, int p) {
    std::vector<int> temp(p);  // Временный вектор для хранения p первых элементов

    // Копируем первые p элементов во временный вектор
    for (int i = 0; i < p; i++) {
        temp[i] = arr[i];
    }

    // Сдвигаем оставшиеся элементы
    for (int i = 0; i < k - p; i++) {
        arr[i] = arr[i + p];
    }

    // Возвращаем первые p элементов в конец массива
    for (int i = 0; i < p; i++) {
        arr[k - p + i] = temp[i];
    }
}

// Функция для отображения контекстного меню
void displayMenu() {
    std::cout << "Лабораторная работа No4" << std::endl;
    std::cout << "Выполнил: Ганиев Абубакр" << std::endl;
    std::cout << "Группа: 453505" << std::endl;
    std::cout << "Вариант 6" << std::endl;
    std::cout << "Задание: Сдвинуть элементы массива циклически на p позиций влево" << std::endl;
    std::cout << "===========================================" << std::endl;
}

// Функция для ввода массива
void inputArray(std::vector<int>& arr, int k) {
    std::cout << "Введите элементы массива:" << std::endl;
    for (int i = 0; i < k; i++) {
        while (!(std::cin >> arr[i])) {
            std::cout << "Неверный ввод. Пожалуйста, введите целое число:" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // очищаем буфер
        }
    }
}

int main() {
    int k, p;
    bool repeat = true;
    char choice;

    while (repeat) {
        // Вывод контекстного меню
        displayMenu();

        // Ввод числа элементов массива с проверкой
        std::cout << "Введите количество элементов массива: ";
        while (!(std::cin >> k) || k <= 0) {
            std::cout << "Неверный ввод. Пожалуйста, введите положительное целое число: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // очищаем буфер
        }

        // Создаем вектор для хранения элементов
        std::vector<int> arr(k);

        // Ввод массива
        inputArray(arr, k);

        // Ввод количества позиций для сдвига с проверкой
        std::cout << "Введите количество позиций для сдвига влево: ";
        while (!(std::cin >> p) || p < 0) {
            std::cout << "Неверный ввод. Пожалуйста, введите неотрицательное целое число: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // очищаем буфер
        }

        // Приведение p в корректные границы (чтобы было меньше k)
        p = p % k;

        // Выполнение циклического сдвига
        cyclicShiftLeft(arr, k, p);

        // Вывод результата
        std::cout << "Результат после циклического сдвига:" << std::endl;
        for (int i = 0; i < k; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

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