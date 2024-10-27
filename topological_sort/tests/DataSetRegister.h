#pragma once
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>


struct DataSet{
    std::string description;
    std::unordered_map<std::string, std::vector<std::string>> graph;
    bool can_be_sorted;
};

std::queue<DataSet> GenerateDataSets();
