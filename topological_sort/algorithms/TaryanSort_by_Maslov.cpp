#include <vector>
#include <string>
#include <unordered_map>
#include "algorithms.h"
#include <stack>
#include <sstream>
using namespace std;

void dfs(string node, unordered_map<string, vector<string>>& graph, unordered_map<string, bool>& visited, unordered_map<string, bool> visitedway, bool& cycle, stack<string>& Stack) {
    // Помечаем текущую вершину как посещенную
    visited[node] = true;
    visitedway[node] = true;
    // Рекурсивно посещаем все соседние вершины
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

    // Добавляем текущую вершину в стек после посещения всех соседей
    Stack.push(node);
}

vector<string> TaryanSort_by_Maslov(unordered_map<string, vector<string>>& graph) {
    unordered_map<string, bool> visited;
    unordered_map<string, bool> visitedway;
    bool cycle = false;
    stack<string> Stack;
    vector<string> sortedOrder;
    // Проходим по всем вершинам графа
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

    // Извлекаем элементы из стека в вектор для получения результата
    
    while (!Stack.empty()) {
        sortedOrder.push_back(Stack.top());
        Stack.pop();
    }

    return sortedOrder;
}
