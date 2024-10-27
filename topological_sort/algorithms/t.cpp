#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include "algorithms.h"

using namespace std;


std::vector<std::string> topologicalSort(std::unordered_map<std::string, std::vector<std::string>> &graph) {
    std::unordered_map<string, int> inDegree;
    std::queue<string> zeroInDegreeQueue;
    std::vector<string> topologicalOrder;

    // Шаг 1: Подсчет степеней входа
    for (const auto& pair : graph) {
        for (auto neighbor : pair.second) {
            inDegree[neighbor]++;
        }
    }

    // Шаг 2: Инициализация очереди
    for (const auto& pair : graph) {
        string vertex = pair.first;
        if (inDegree[vertex] == 0) {
            zeroInDegreeQueue.push(vertex);
        }
    }

    // Шаг 3: Извлечение из очереди
    while (!zeroInDegreeQueue.empty()) {
        string current = zeroInDegreeQueue.front();
        zeroInDegreeQueue.pop();
        topologicalOrder.push_back(current);

        for (string neighbor : graph.at(current)) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                zeroInDegreeQueue.push(neighbor);
            }
        }
    }

    // Шаг 4: Проверка на наличие циклов
    if (topologicalOrder.size() != graph.size()) {
        std::cout << "Граф содержит цикл. Топологическая сортировка невозможна." << std::endl;
    } else {
        // Вывод результата
        std::cout << "Топологическая сортировка: ";
        for (string vertex : topologicalOrder) {
            std::cout << vertex << " ";
        }
        std::cout << std::endl;
    }

    return topologicalOrder;
}
