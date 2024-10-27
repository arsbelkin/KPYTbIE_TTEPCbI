#pragma once
#include <unordered_map>
#include <vector>
#include "../algorithms/algorithms.h"


// макрос для запуска кода
#define RUN(x) { \
        Run(#x, x, graph, dataset);\
    }

//функция, которая проверяет, что order содержит неповторяющиеся элементы
bool IsSet(std::vector<std::string> &order);

//функция, которая проверят является ли топологическая сортировка корректной
bool IsCorrectTopologicalSort(
    std::unordered_map<std::string, std::vector<std::string>> &graph,
    std::vector<std::string> &order
);

// основная функция, которая производит расчет времени
void Run(std::string method_name,
    Algorithm p,
    std::unordered_map<std::string,
    std::vector<std::string>> &graph,
    std::string &dataset
);
