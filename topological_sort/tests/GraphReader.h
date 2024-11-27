#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <string>


std::unordered_map<int, std::unordered_set<int>> ConvertStrToInt(
    const std::unordered_map<std::string, std::unordered_set<std::string>>& in
);


template<typename T>
std::unordered_map<T, std::unordered_set<T>> readGraphFromFile(
    const std::string &path_to_file
)
{
    std::unordered_map<T, std::unordered_set<T>> graph;

    std::ifstream file(path_to_file);
    std::string line;

    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return graph; 
    }

    while (getline(file, line)){
        if (line.empty()) {
            continue;
        }

        std::istringstream iss(line);
        T from, to;
        iss >> from;
        if (iss.peek()==' '){
            iss >> to;
            graph[from].emplace(to);
        }
        else graph[from] = {};
    }

    file.close();
    return graph;
}
