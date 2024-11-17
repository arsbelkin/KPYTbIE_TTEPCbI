#pragma once
#include <unordered_map>
#include <vector>
#include "../algorithms/algorithms.h"
#include "DataSetRegister.h"
#include "logger.h"


// макрос для запуска кода
#define RUN(x) { \
        Run(#x, x, ds, oss);\
    }

//функция для вывода результата топологической сортировки
void print_TS(std::vector<std::string> &order, std::ostringstream &oss, std::string file_name);

//функция для записи в файл топологической сортировки
void save_TS(std::vector<std::string> &TS, std::ofstream &file);

//подсчет ребер графа
int edges_number(std::unordered_map<std::string, std::vector<std::string>> &graph);

//функция, которая проверяет, что order содержит неповторяющиеся элементы
bool IsSet(const std::vector<std::string> &order);

//функция, которая проверят является ли топологическая сортировка корректной
bool IsCorrectTopologicalSort(
    const std::unordered_map<std::string, std::vector<std::string>> &graph,
    const std::vector<std::string> &order
);

// основная функция, которая производит расчет времени
void Run(std::string method_name, Algorithm alg, DataSet ds, std::ostringstream &oss);
