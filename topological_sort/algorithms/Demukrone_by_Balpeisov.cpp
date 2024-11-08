#include "algorithms.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> Demukrone_by_Balpeisov(unordered_map<string, vector<string>>& graph)
{
    int n = graph.size(); //кол-во вершин
    string vertex[n];  //массив с вершинами для ассоциации индексов с матрицей
    int adj_matrix[n][n] {}; //строка - начальная вершина, столбец - конечная
    unordered_map<string, int>lvl_vertex; //уровни вершин графа
    int id_sv; //индекс начальной вершины
    int id_ev; //индекс конечной вершины
    int i = 0; //вспомогательная перемен для создания массива с вершинами
    int sum_row;
    vector<string> sorted_graph, pop_elem;

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

    do{
        for (int id_col = 0; id_col<n; id_col++)
        {
            if (std::ranges::find(sorted_graph.begin(), sorted_graph.end(), vertex[id_col]) != sorted_graph.end())
            {
                continue;
            }
            sum_row = 0;
            for (int id_row = 0; id_row<n; id_row++)
            {
                sum_row += adj_matrix[id_row][id_col];
            }
            lvl_vertex.emplace(vertex[id_col], sum_row);
        }

        for (auto& pair: lvl_vertex)
        {
            if (pair.second == 0)
                pop_elem.push_back(pair.first);
        }

        sorted_graph.insert(sorted_graph.end(), pop_elem.begin(), pop_elem.end());

        for (auto& el: pop_elem)
        {
            id_sv = vertex->find(el);
            for (id_ev = 0; id_ev<n; id_ev++)
            {
                adj_matrix[id_sv][id_ev] = 0;
            }
        }
        pop_elem.clear();
        lvl_vertex.clear();
    } while (!lvl_vertex.empty());
    
    for (auto& el: sorted_graph)
        std::cout<<el<<std::endl;
    std::cout<<"piska\n";
    return(sorted_graph);
}