#include <iostream>
#include "algorithms.h"
#include <string>

using namespace std;


bool is_sorted(std::unordered_map<std::string, std::vector<std::string>> graph, std::vector<std::string> order){
    unordered_map<string, int> in_degree;

    for (auto& [u, _]: graph){
        in_degree[u] = 0;
    }

    for (auto& [u, _]: graph){
        for (auto& v: graph[u]){
            ++in_degree[v];
        }
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

// test
int main(){
    std::unordered_map<std::string, std::vector<std::string>> graph = {
        {"A", {"B", "C"}},
        {"B", {"D", "C"}},
        {"C", {"D"}},
    };

    std::vector<std::string> order={"A", "C", "B", "D"};

    return 0;
}
