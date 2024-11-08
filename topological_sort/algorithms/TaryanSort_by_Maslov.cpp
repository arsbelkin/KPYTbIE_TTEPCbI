#include <vector>
#include <string>
#include <unordered_map>
#include "algorithms.h"

#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

void dfs(int node, unordered_map<string, vector<string>>& graph, unordered_map<int, bool>& visited, stack<int>& Stack) {
    // Помечаем текущую вершину как посещенную
    visited[node] = true;

    // Извлекаем соседей из строки
    stringstream ss(graph[node]);
    string neighbor;
    
    // Рекурсивно посещаем все соседние вершины
    while (getline(ss, neighbor, ',')) {
        int neighborNode = stoi(neighbor); // Преобразуем строку в целое число
        if (!visited[neighborNode]) {
            dfs(neighborNode, graph, visited, Stack);
        }
    }

    // Добавляем текущую вершину в стек после посещения всех соседей
    Stack.push(node);
}

vector<int> topologicalSort(unordered_map<string, vector<string>>& graph) {
    unordered_map<int, bool> visited;
    stack<int> Stack;

    // Проходим по всем вершинам графа
    for (auto& pair : graph) {
        int node = pair.first;
        if (!visited[node]) {
            dfs(node, graph, visited, Stack);
        }
    }

    // Извлекаем элементы из стека в вектор для получения результата
    vector<int> sortedOrder;
    while (!Stack.empty()) {
        sortedOrder.push_back(Stack.top());
        Stack.pop();
    }

    return sortedOrder;
}

int main() {
    unordered_map<string, vector<string>> graph;

    // Пример графа (ключ: вершина, значение: соседние вершины через запятую)
    graph[F] = ("C", "A");
    graph[4] = ("A", "B");
    graph[3] = ("B");
    graph[2] = ("D");
    graph["B"] = ("");
    graph["A"] = ("");

    vector<int> sortedOrder = topologicalSort(graph);

    cout << "Топологически отсортированный порядок: ";
    for (int node : sortedOrder) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
