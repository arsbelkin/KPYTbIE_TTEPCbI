#include "algorithms.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;


void dfs(string node, unordered_map<string, vector<string>>& graph, unordered_map<string, bool>& visited, unordered_map<string, bool> visitedway, bool& cycle)
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

vector<string> Demukrone_by_Balpeisov(unordered_map<string, vector<string>>& graph)
{
    int n = graph.size(); //кол-во вершин
    // !!!!!!!!
    unordered_map<string, int> inDegree; // входящие степени вершины
    unordered_set<string> pop_elem; // удаленные элементы
    vector<string> sorted_graph; //сортированный граф

    bool cycle = false; //наличие цикла
    unordered_map<string, bool> visited; //посещённые вершины за все иттерации
    unordered_map<string, bool> visitedway; //посещённые вершины за эту иттерацию

    for (auto& pair: graph)     
    {
        if (cycle) 
        {
            sorted_graph.push_back("-1");
            return sorted_graph;
        }
        string node = pair.first;
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
