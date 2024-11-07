#include <queue>
#include "DataSetRegister.h"
#include "GraphReader.h"


std::queue<DataSet> GenerateDataSets(){
    return std::queue<DataSet>({
        {"empty set", {}, 1},
        {"empty graph", readGraphFromFile("./files/emptyGraph.txt"), 1},
        {"one vertex graph", readGraphFromFile("./files/oneVertexGraph.txt"), 1},
        {"small correct graph", readGraphFromFile("./files/smallCorrectGraph.txt"), 1},
        {"large numeric correct graph", readGraphFromFile("./files/largeCorrectGraph.txt"), 1},
        {"small cycle graph", readGraphFromFile("./files/smallCycleGraph.txt"), 0},
        {"large numeric cycle graph", readGraphFromFile("./files/largeCycleGraph.txt"), 0},
    });
}
