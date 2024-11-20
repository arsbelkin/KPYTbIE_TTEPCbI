#include <vector>
#include <string>
#include <unordered_map>
#include "algorithms.h"
#include <stack>
#include <sstream>
using namespace std;

void dfs(string node, unordered_map<string, vector<string>>& graph, unordered_map<string, bool>& visited, unordered_map<string, bool> visitedway, bool& cycle, stack<string>& Stack) {
    visited[node] = true;
    visitedway[node] = true;
    for (auto& neighbor: graph[node]) {
        if (cycle)
            return;
        if (visitedway[neighbor])
        {
            cycle = true;
            return;

        }
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited,visitedway, cycle, Stack);
        }
    }
    Stack.push(node);
}

vector<string> TaryanSort_by_Maslov(unordered_map<string, vector<string>>& graph) {
    unordered_map<string, bool> visited;
    unordered_map<string, bool> visitedway;
    bool cycle = false;
    stack<string> Stack;
    vector<string> sortedOrder;
    for (auto& pair : graph) {
        if (cycle) 
        {
            sortedOrder.push_back("-1");
            return sortedOrder;
        }
        if (!visited[pair.first]) {
            dfs(pair.first, graph, visited,visitedway, cycle, Stack);
        }
    }
    while (!Stack.empty()) {
        sortedOrder.push_back(Stack.top());
        Stack.pop();
    }
    return sortedOrder;
}
