#pragma once
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>


template<typename T>
struct DataSet{
    std::string description;
    std::unordered_map<T, std::vector<T>> graph;
    bool can_be_sorted;
};


std::queue<DataSet<int>> GenerateIntDataSets();
std::queue<DataSet<std::string>> GenerateStringDataSets();
