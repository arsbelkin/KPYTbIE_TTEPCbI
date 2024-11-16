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
    vector<string> vertex;  //массив с вершинами для ассоциации индексов с матрицей
    vector<vector<int>> adj_matrix(n, vector<int>(n, 0)); //строка - начальная вершина, столбец - конечная

    // !!!!!!!!!!
    unordered_map<string, int> inDegree; // входящие степени вершины
    unordered_set<string> pop_elem; // удаленные элементы

    unordered_map<string, int> lvl_vertex; //уровни вершин графа
    int id_sv; //индекс начальной вершины
    int id_ev; //индекс конечной вершины
    bool cycle = false; //наличие цикла
    unordered_map<string, bool> visited; //посещённые вершины за все иттерации
    unordered_map<string, bool> visitedway; //посещённые вершины за эту иттерацию
    int sum_col; //полустепень входаы
    vector<string> sorted_graph, cycle_graph = {"-1"}, op_elem; //сортированный граф, для графа с циклами, удалённые вершины с нулевым уровнем

    for (auto& pair: graph)     
    {
        if (cycle) 
        {
            return cycle_graph;
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
                pop_elem.emplace(pair.first);
                sorted_graph.push_back(pair.first);
                if (pop_elem.count(pair.first) > 0){
                    for (auto& v: graph[pair.first]){
                        --inDegree[v];
                    }
                }
            }
        }
    }
    
    return(sorted_graph);
}
