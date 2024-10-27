#include <iostream>
#include "tests_functions.h"
#include <string>
#include <chrono>
#include <unordered_map>
#include <unordered_set>
#include "GraphReader.h"
#include "../algorithms/algorithms.h"

using namespace std;
using namespace chrono;


bool IsSet(std::vector<std::string> &order){
    unordered_set<std::string> order_set;

    for (auto& elem: order){
        order_set.emplace(elem);
    }

    return order.size() == order_set.size();
}


bool IsCorrectTopologicalSort(
    std::unordered_map<std::string, std::vector<std::string>> &graph,
    std::vector<std::string> &order
){
    if ((graph.size() != order.size()) || !IsSet(order)){
        return false;
    }

    unordered_map<string, int> position;
    
    for (auto i=0; i < order.size(); ++i){
        position[order[i]] = i;
    }

    for (const auto& pair: graph){
        string u = pair.first;
        for (string v: pair.second){
            if (position[u] > position[v]){
                return false;
            }
        }
    }

    return true;
}


void Run(std::string method_name, Algorithm p, std::unordered_map<std::string, std::vector<std::string>> &graph, std::string &dataset){
    auto start = system_clock::now();
    std::vector<std::string> result = p(graph);
    auto finish = system_clock::now();
    auto time = duration_cast<microseconds>(finish - start).count();

    cout << method_name << endl;
    cout << "dataset: " << dataset << endl;
    cout << "time: " << time << endl;
    cout << "is sorted: " << IsCorrectTopologicalSort(graph, result) << endl;
    cout << endl;
}
