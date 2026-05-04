#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Функция для очистки динамической памяти
void free_memory(int *keys, char **data, int n) {
    for (int i = 0; i < n; i++) {
        free(data[i]);
    }
    free(data);
    free(keys);
}

// Печать таблицы
void print_table(int *keys, char **data, int n) {
    printf("\n--- Текущее состояние таблицы ---\n");
    printf("%-10s | %s\n", "Ключ", "Запись (Текст)");
    printf("-------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-10d | %s\n", keys[i], data[i]);
    }
    printf("-------------------------------\n");
}

// Сортировка Шелла
void shell_sort(int *keys, char **data, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp_key = keys[i];
            char *temp_data = data[i];
            
            int j;
            for (j = i; j >= gap && keys[j - gap] > temp_key; j -= gap) {
                keys[j] = keys[j - gap];
                data[j] = data[j - gap];
            }
            keys[j] = temp_key;
            data[j] = temp_data;
        }
    }
}

// Двоичный поиск
int binary_search(int *keys, int n, int search_key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (keys[mid] == search_key)
            return mid;
        if (keys[mid] < search_key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n;
    printf("Введите количество элементов (минимум 17 для 7 варианта): ");
    scanf("%d", &n);

    if (n < 1) return 1;

    int *keys = (int *)malloc(n * sizeof(int));
    char **data = (char **)malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++) {
        data[i] = (char *)malloc(256 * sizeof(char));
        printf("Элемент [%d]. Введите ключ (int) и текст: ", i);
        scanf("%d", &keys[i]);
        getchar();
        fgets(data[i], 256, stdin);
        data[i][strcspn(data[i], "\n")] = 0;
    }

    // Исходное состояние
    printf("\nИсходная таблица:");
    print_table(keys, data, n);

    // Сортировка
    shell_sort(keys, data, n);
    printf("\nТаблица после сортировки методом Шелла:");
    print_table(keys, data, n);

    // Поиск
    int s_key;
    printf("\nВведите ключ для двоичного поиска: ");
    scanf("%d", &s_key);

    int result_idx = binary_search(keys, n, s_key);
    if (result_idx != -1) {
        printf("Элемент найден! Индекс: %d, Запись: %s\n", result_idx, data[result_idx]);
    } else {
        printf("Элемент с таким ключом не найден.\n");
    }

    // Освобождение памяти
    free_memory(keys, data, n);

    return 0;
}