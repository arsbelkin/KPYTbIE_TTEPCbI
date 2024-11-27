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


template<typename T>
void save_TS(std::vector<T> &TS, std::ofstream &file){
    for (auto& v: TS){
        file << v << std::endl;
    }
}

template<typename T>
void print_TS(std::vector<T> &order, std::ostringstream &oss, std::string file_name){
    oss << "Topological sort: ";

    if (order.size() > 100){
        std::ofstream file("TS/" + file_name + ".txt");
        if (file.is_open()) {
            save_TS(order, file);
            oss << "was saved in file " + file_name + ".txt";
        }
    } else {
        for (auto& v: order) {
            oss << v << " ";
        } 
    }
    oss << std::endl;
}

template<typename T>
int edges_number(std::unordered_map<T, std::unordered_set<T>> &graph){
    int counter = 0;

    for (auto& pair: graph){
        counter += pair.second.size();
    }

    return counter;
}

template<typename T>
bool IsSet(const std::vector<T> &order){
    std::unordered_set<T> order_set;

    for (const auto& elem: order){
        if (!order_set.emplace(elem).second){
            return false;
        }
    }

    return true;
}

template<typename T>
bool IsCorrectTopologicalSort(
    const std::unordered_map<T, std::unordered_set<T>> &graph,
    const std::vector<T> &order
){
    if ((graph.size() != order.size()) || !IsSet(order)){
        return false;
    }

    std::unordered_map<T, int> position;
    
    for (int i=0; i < order.size(); ++i){
        position[order[i]] = i;
    }

    for (const auto& [u,V]: graph){
        for (const auto& v: V){
            if (position[u] > position[v]){
                return false;
            }
        }
    }

    return true;
}


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
    oss << "Number of vertices: " << ds.graph.size() << std::endl;
    oss << "Number of edges: " << edges_number(ds.graph) << std::endl;
    oss << "Can be sorted: " << ds.can_be_sorted << std::endl;
    oss << "Time: " << time << std::endl;
    print_TS(result, oss, method_name + " " + ds.description);

    oss << "Is sorted correctly: ";
    if (ds.can_be_sorted){
        oss << IsCorrectTopologicalSort(ds.graph, result) << std::endl;
    } else {
        oss << (!result.size()) << std::endl;
    }

    oss << "----------------------------------------" << std::endl;
}
