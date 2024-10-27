#pragma once
#include <unordered_map>
#include <vector>
#include "../algorithms/algorithms.h"
#include "DataSetRegister.h"
#include "logger.h"


// макрос для запуска кода
#define RUN(x) { \
        Run(#x, x, ds, logger, oss);\
    }

//функция для вывода результата топологической сортировки
void print_TS(std::vector<std::string> &order, std::ostringstream &oss);

//подсчет ребер графа
int edges_number(std::unordered_map<std::string, std::vector<std::string>> &graph);

//функция, которая проверяет, что order содержит неповторяющиеся элементы
bool IsSet(std::vector<std::string> &order);

//функция, которая проверят является ли топологическая сортировка корректной
bool IsCorrectTopologicalSort(
    std::unordered_map<std::string, std::vector<std::string>> &graph,
    std::vector<std::string> &order
);

// основная функция, которая производит расчет времени
void Run(std::string method_name, Algorithm p, DataSet ds, Logger &logger, std::ostringstream &oss);
