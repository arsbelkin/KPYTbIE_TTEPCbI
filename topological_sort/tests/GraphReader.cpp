#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <string>
#include "GraphReader.h"

using namespace std;


#define ATOI(s) s[0]-'A'+1

std::unordered_map<int, std::vector<int>> ConvertStrToInt(
    const std::unordered_map<std::string, std::vector<std::string>>& in
)
{
    std::unordered_map<int, std::vector<int>> graph;
    for (auto& [k, V]: in) {
        if (k.empty()) {
            continue;
        }
        std::vector<int> res;
        for (auto& v:V){
            if (!v.empty()) res.push_back(ATOI(v));
        }
        graph[ATOI(k)] = res;
    }
    return graph;
}
