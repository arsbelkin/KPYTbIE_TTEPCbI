#include <iostream>
#include "tests_functions.h"
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

using namespace std;
using namespace chrono;


void save_TS(std::vector<std::string> &TS, std::ofstream &file){
    for (auto& v: TS){
        file << v << endl;
    }
}

void print_TS(std::vector<std::string> &order, std::ostringstream &oss, std::string file_name){
    oss << "Topological sort: ";

    if (order.size() > 100){
        ofstream file("TS/" + file_name + ".txt");
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

int edges_number(std::unordered_map<std::string, std::vector<std::string>> &graph){
    int counter = 0;

    for (auto& pair: graph){
        counter += pair.second.size();
    }

    return counter;
}


bool IsSet(const std::vector<std::string> &order){
    unordered_set<std::string> order_set;

    for (const auto& elem: order){
        if (!order_set.emplace(elem).second){
            return false;
        }
    }

    return true;
}


bool IsCorrectTopologicalSort(
    const std::unordered_map<std::string, std::vector<std::string>> &graph,
    const std::vector<std::string> &order
){
    if ((graph.size() != order.size()) || !IsSet(order)){
        return false;
    }

    unordered_map<string, int> position;
    
    for (int i=0; i < order.size(); ++i){
        position[order[i]] = i;
    }

    for (const auto& pair: graph){
        const string& u = pair.first;
        for (const string& v: pair.second){
            if (position[u] > position[v]){
                return false;
            }
        }
    }

    return true;
}


void Run(std::string method_name, Algorithm alg, DataSet ds, std::ostringstream &oss){
    oss << "----------------------------------------" << endl;

    auto start = system_clock::now();
    std::vector<std::string> result = alg(ds.graph);
    auto finish = system_clock::now();
    auto time = duration_cast<microseconds>(finish - start).count();

    oss << "Method: " << method_name << endl;
    oss << "Dataset: " << ds.description << endl;
    oss << "Number of vertices: " << ds.graph.size() << endl;
    oss << "Number of edges: " << edges_number(ds.graph) << endl;
    oss << "Can be sorted: " << ds.can_be_sorted << endl;
    oss << "Time: " << time << endl;
    print_TS(result, oss, method_name + " " + ds.description);

    oss << "Is sorted correctly: ";
    if (ds.can_be_sorted){
        oss << IsCorrectTopologicalSort(ds.graph, result) << endl;
    } else {
        oss << (result[0] == "-1") << endl;
    }

    oss << "----------------------------------------" << endl;
}
