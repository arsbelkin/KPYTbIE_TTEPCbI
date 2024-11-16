#include "algorithms.h"
#include <iostream>
#include <string>
#include <unordered_map>
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
            dfs(neighbor, graph, visited,visitedway, cycle);
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
    unordered_map<string, int>lvl_vertex; //уровни вершин графа
    int id_sv; //индекс начальной вершины
    int id_ev; //индекс конечной вершины
    bool cycle = false; //наличие цикла
    unordered_map<string, bool> visited; //посещённые вершины за все иттерации
    unordered_map<string, bool> visitedway; //посещённые вершины за эту иттерацию
    int sum_col; //полустепень входа
    vector<string> sorted_graph, cycle_graph = {"-1"}, pop_elem; //сортированный граф, для графа с циклами, удалённые вершины с нулевым уровнем

    for (auto& pair: graph)     
    {
        if (cycle) 
        {
            return cycle_graph;
        }
        string node = pair.first;
        if (!visited[node]) {
            dfs(node, graph, visited,visitedway, cycle);
        }
        vertex.push_back(pair.first);
    }

    for (auto& pair: graph)
    {
        id_sv = find(begin(vertex), end(vertex), pair.first) - begin(vertex);
        for (auto& v: pair.second)
        {
            id_ev = find(begin(vertex), end(vertex), v) - begin(vertex);
            adj_matrix[id_sv][id_ev] = 1;
        }
    }

    while (sorted_graph.size() < n)
    {
        for (int id_col = 0; id_col<n; id_col++)
        {
            if (find(sorted_graph.begin(), sorted_graph.end(), vertex[id_col]) != sorted_graph.end())
            {
                continue;
            }
            sum_col = 0;
            for (int id_row = 0; id_row<n; id_row++)
            {
                sum_col += adj_matrix[id_row][id_col];
            }
            lvl_vertex.emplace(vertex[id_col], sum_col);
            if (sum_col == 0)
            {
                pop_elem.push_back(vertex[id_col]);
                sorted_graph.push_back(vertex[id_col]);
            }
        }

        for (auto& el: pop_elem)
        {
            id_sv = find(begin(vertex), end(vertex), el) - begin(vertex);
            for (id_ev = 0; id_ev<n; id_ev++)
            {
                adj_matrix[id_sv][id_ev] = 0;
            }
        }
        pop_elem.clear();
        lvl_vertex.clear();
    }
    
    return(sorted_graph);
}
