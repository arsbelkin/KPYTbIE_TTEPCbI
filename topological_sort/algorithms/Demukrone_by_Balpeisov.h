#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

template<typename T>
void dfs(T node, std::unordered_map<T, std::vector<T>>& graph, std::unordered_map<T, bool>& visited, std::unordered_map<T, bool> visitedway, bool& cycle)
{
    // помечаем текущую вершину как посещенную
    visited[node] = true;
    visitedway[node] = true;
    if (cycle)
        return;
    // рекурсивно посещаем все соседние вершины
    for (auto& neighbor: graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, visitedway, cycle);
        }
        if (visitedway[neighbor])
        {
            cycle = true;
            return;
        }
    }
}

template <typename T>
vector<T> Demukrone_by_Balpeisov(unordered_map<T, vector<T>>& graph)
{
    int n = graph.size(); //кол-во вершин
    // !!!!!!!!
    std::unordered_map<T, int> inDegree; // входящие степени вершины
    std::unordered_set<T> pop_elem; // удаленные элементы
    std::vector<T> sorted_graph; //сортированный граф

    bool cycle = false; //наличие цикла
    std::unordered_map<T, bool> visited; //посещённые вершины за все иттерации
    std::unordered_map<T, bool> visitedway; //посещённые вершины за эту иттерацию

    for (auto& pair: graph)     
    {
        if (cycle) 
        {
            sorted_graph.push_back("-1");
            return sorted_graph;
        }
        T node = pair.first;
        if (!visited[node]) {
            dfs(node, graph, visited, visitedway, cycle);
        }
        inDegree.emplace(pair.first, 0);
    }

    for (auto& pair: graph)
    {
        for (auto& v: pair.second)
        {
            ++inDegree[v];
        }
    }

    while (sorted_graph.size() < n)
    {
        for (auto& pair: inDegree){
            if (pair.second == 0){
                if (pop_elem.count(pair.first) == 0){
                    sorted_graph.push_back(pair.first);
                    for (auto& v: graph[pair.first]){
                        --inDegree[v];
                    }
                }

                pop_elem.emplace(pair.first);
            }
        }
    }
    
    return(sorted_graph);
}
