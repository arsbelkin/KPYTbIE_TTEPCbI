#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <string>


//функция для считывая графа из файла
template<typename T>
std::unordered_map<T, std::vector<T>> readGraphFromFile(
    const std::string &path_to_file
){
    std::unordered_map<T, std::vector<T>> graph;

    std::ifstream file(path_to_file);
    std::string line;

    if (!file) {
        std::cerr << "Error opening file!" << endl;
        return graph; 
    }

    while (getline(file, line)){
        if (line.empty()) {
            continue;
        }

        istringstream iss(line);
        T from, to;

        if (iss >> from >> to) {
            graph[from].push_back(to);
        }

        if (!from.empty() && to.empty()){
            graph[from] = {};
        }
        
    }

    file.close();

    return graph;
}
