#include <iostream>
#include "algorithms.h"
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> topologicalSort_by_Balpeisov(unordered_map<string, vector<string>>& graph)
{
    int n = graph.size(); //кол-во вершин
    string vertex[n];  //массив с вершинами для ассоциации индексов с матрицей
    int adj_matrix[n][n] {}; //строка - начальная вершина, столбец - конечная
    unordered_map<string, int>lvl_vertex; //уровни вершин графа
    int id_sv; //индекс начальной вершины
    int id_ev; //индекс конечной вершины
    int i = 0; //вспомогательная перемен для создания массива с вершинами

    for (auto& pair: graph)     
    {
        vertex[i]=pair.first;
        i++;
    }

    for (auto& pair: graph)
    {
        id_sv = vertex->find(pair.first);
        for (auto& v: pair.second)
        {
            id_ev = vertex->find(v);
            adj_matrix[id_sv][id_ev] = 1;
        }
    }

    for (int id_col = 0; id_col<n; id_col++)
    {
        int sum_row = 0;
        for (int id_row = 0; id_row<n; id_row++)
        {
            sum_row += adj_matrix[id_row][id_col];
        }
        lvl_vertex.emplace(vertex[id_col], sum_row);
    }
}