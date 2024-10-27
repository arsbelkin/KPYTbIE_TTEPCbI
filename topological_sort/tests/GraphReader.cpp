#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <string>
#include "GraphReader.h"

using namespace std;


std::unordered_map<std::string, std::vector<std::string>> readGraphFromFile(
    const std::string &path_to_file
){
    std::unordered_map<std::string, std::vector<std::string>> graph;

    ifstream file(path_to_file);
    string line;

    if (!file) {
        std::cerr << "Error opening file!" << endl;
        return graph; 
    }

    while (getline(file, line)){
        if (line.empty()) {
            continue;
        }

        istringstream iss(line);
        string from, to;

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
