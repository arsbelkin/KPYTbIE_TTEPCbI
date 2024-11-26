#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <sstream>
using namespace std;
template<typename T>
void dfs(T node, std::unordered_map<T, std::vector<T>>& graph, std::unordered_map<T, bool>& visited, std::unordered_map<T, bool> visitedway, bool& cycle, std::stack<T>& Stack) {
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
template<typename T>
std::vector<T> TaryanSort_by_Maslov(std::unordered_map<T, std::vector<T>>& graph) {
    std::unordered_map<T, bool> visited;
    std::unordered_map<T, bool> visitedway;
    bool cycle = false;
    std::stack<T> Stack;
    std::vector<T> sortedOrder;
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
