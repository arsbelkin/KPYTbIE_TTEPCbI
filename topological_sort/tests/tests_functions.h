#pragma once
#include <unordered_map>
#include <vector>
#include "../algorithms/algorithms.h"


#define RUN(x) { \
        Run(#x, x, graph, dataset);\
    }


bool IsSet(std::vector<std::string> &order);

bool IsCorrectTopologicalSort(
    std::unordered_map<std::string, std::vector<std::string>> &graph,
    std::vector<std::string> &order
);


void Run(std::string method_name, Algorithm p, std::unordered_map<std::string, std::vector<std::string>> &graph, std::string &dataset);
