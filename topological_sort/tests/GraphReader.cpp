#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <string>
#include "GraphReader.h"

using namespace std;


std::unordered_map<std::string, std::vector<std::string>> readStringGraphFromFile(
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



std::unordered_map<int, std::vector<int>> readIntGraphFromFile(
    const std::string &path_to_file
)
{
       std::unordered_map<int, std::vector<int>> graph;

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
        int from, to;
        iss >> from;
        if (iss.peek()==' ')
        {
            iss>> to;
            graph[from].push_back(to);
        }
        else
            graph[from] = {};
    }
    file.close();
    return graph;
}