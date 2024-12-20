#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <string>
#include "GraphReader.h"

using namespace std;


#define ATOI(s) s[0]-'A'+1

std::unordered_map<int, std::unordered_set<int>> ConvertStrToInt(
    const std::unordered_map<std::string, std::unordered_set<std::string>>& in
)
{
    std::unordered_map<int, std::unordered_set<int>> graph;
    for (auto& [k, V]: in) {
        if (k.empty()) {
            continue;
        }
        std::unordered_set<int> res;
        for (auto& v:V){
            if (!v.empty()) res.emplace(ATOI(v));
        }
        graph[ATOI(k)] = res;
    }
    return graph;
}
