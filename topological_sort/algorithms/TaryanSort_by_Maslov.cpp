#include <vector>
#include <string>
#include <unordered_map>
#include "algorithms.h"
#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

void dfs(string node, unordered_map<string, vector<string>>& graph, unordered_map<string, bool>& visited, stack<string>& Stack) {
    // Помечаем текущую вершину как посещенную
    visited[node] = true;
    
    // Рекурсивно посещаем все соседние вершины
    for (auto& neighbor: graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, Stack);
        }
    }

    // Добавляем текущую вершину в стек после посещения всех соседей
    Stack.push(node);
}

vector<string> TaryanSort_by_Maslov(unordered_map<string, vector<string>>& graph) {
    unordered_map<string, bool> visited;
    stack<string> Stack;

    // Проходим по всем вершинам графа
    for (auto& pair : graph) {
        string node = pair.first;
        if (!visited[node]) {
            dfs(node, graph, visited, Stack);
        }
    }

    // Извлекаем элементы из стека в вектор для получения результата
    vector<string> sortedOrder;
    while (!Stack.empty()) {
        sortedOrder.push_back(Stack.top());
        Stack.pop();
    }

    return sortedOrder;
}
