#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>
#include <unordered_map>
#include <unordered_set>
#include "GraphReader.h"
#include "DataSetRegister.h"
#include "../algorithms/algorithms.h"
#include "logger.h"


using namespace std::chrono;
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
template<typename T>
void Run(std::string method_name, Algorithm<T> alg, DataSet<T> ds, std::ostringstream &oss){
    oss << "----------------------------------------" << std::endl;

    auto start = system_clock::now();
    std::vector<T> result = alg(ds.graph);
    auto finish = system_clock::now();
    auto time = duration_cast<microseconds>(finish - start).count();

    oss << "Method: " << method_name << std::endl;
    oss << "Dataset: " << ds.description << std::endl;
    // oss << "Number of vertices: " << ds.graph.size() << std::endl;
    // oss << "Number of edges: " << edges_number(ds.graph) << std::endl;
    // oss << "Can be sorted: " << ds.can_be_sorted << std::endl;
    oss << "Time: " << time << std::endl;
    // print_TS(result, oss, method_name + " " + ds.description);

    // oss << "Is sorted correctly: ";
    // if (ds.can_be_sorted){
    //     oss << IsCorrectTopologicalSort(ds.graph, result) << std::endl;
    // } else {
    //     oss << (!result.size()) << std::endl;
    // }

    oss << "----------------------------------------" << std::endl;
}
