#include <iostream>
#include "algorithms.h"
#include "../tests/DataSetRegister.h"
#include "../tests/tests_functions.h"
#include "stack"

using namespace std;


static string dataset = "";
static bool can_be_sorted = 0;


int main(){
    // auto DataSets = GenerateDataSets();
    auto DataSets = std::stack<DataSet>({
        {"correct data", readGraphFromFile("tests/datasets/correctTS.txt"), 1},
        {"cycle graph", readGraphFromFile("tests/datasets/cycleTS.txt"), 0},
        {"difficult graph", readGraphFromFile("tests/datasets/difficultGraph.txt"), 1},
        {"empty graph", {}, 1}
    });

    while (!DataSets.empty()){
        auto& ds = DataSets.top();
        dataset = ds.description;
        auto& graph = ds.graph;
        can_be_sorted = ds.can_be_sorted;

        RUN(topologicalSort);

        DataSets.pop();
    }

    return 0;
}
