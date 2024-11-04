#include <iostream>
#include "tests_functions.h"
#include <string>
#include <sstream>
#include <chrono>
#include <unordered_map>
#include <unordered_set>
#include "GraphReader.h"
#include "DataSetRegister.h"
#include "../algorithms/algorithms.h"
#include "logger.h"

using namespace std;
using namespace chrono;


void print_TS(std::vector<std::string> &order, std::ostringstream &oss){
    oss << "Topological sort: ";
    for (auto& v: order) {
        oss << v << " ";
    }
    oss << std::endl;
}


int edges_number(std::unordered_map<std::string, std::vector<std::string>> &graph){
    int counter = 0;

    for (auto& pair: graph){
        counter += pair.second.size();
    }

    return counter;
}


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


void Run(std::string method_name, Algorithm p, DataSet ds, std::ostringstream &oss){
    oss << "----------------------------------------" << endl;

    auto start = system_clock::now();
    std::vector<std::string> result = p(ds.graph);
    auto finish = system_clock::now();
    auto time = duration_cast<microseconds>(finish - start).count();

    oss << "Method: " << method_name << endl;
    oss << "Dataset: " << ds.description << endl;
    oss << "Number of vertices: " << ds.graph.size() << endl;
    oss << "Number of edges: " << edges_number(ds.graph) << endl;
    oss << "Can be sorted: " << ds.can_be_sorted << endl;
    oss << "Time: " << time << endl;
    print_TS(result, oss);

    oss << "Is sorted correctly: ";
    if (ds.can_be_sorted){
        oss << IsCorrectTopologicalSort(ds.graph, result) << endl;
    } else if ((result[0] == "-1") && !ds.can_be_sorted){
        oss << "Is sorted correctly: " << "1" << endl;
    }

    oss << "----------------------------------------" << endl;;
}
