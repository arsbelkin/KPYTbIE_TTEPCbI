#pragma once
#include <string>
#include <stack>
#include "GraphReader.h"


struct DataSet{
    std::string description;
    std::unordered_map<std::string, std::vector<std::string>> graph;
    bool can_be_sorted;
};


std::stack<DataSet> GenerateDataSets(){
    return std::stack<DataSet>({
        {"correct data", readGraphFromFile("datasets/correctTS.txt"), 1},
        {"cycle graph", readGraphFromFile("datasets/cycleTS.txt"), 0},
        {"difficult graph", readGraphFromFile("datasets/difficultGraph.txt"), 1},
        {"empty graph", {}, 1}
    });
}
