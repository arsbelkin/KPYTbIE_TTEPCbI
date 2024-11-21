#include <queue>
#include "DataSetRegister.h"
#include "GraphReader.h"


std::queue<DataSet> GenerateDataSets(){
    return std::queue<DataSet>({
        //{"empty set", {}, 1},
        //{"empty graph", readGraphFromFile("../../topological_sort/tests/datasets/files/emptyGraph.txt"), 1},
        //{"one vertex graph", readGraphFromFile("../../topological_sort/tests/datasets/files/oneVertexGraph.txt"), 1},
        //{"small correct graph", readGraphFromFile("../../topological_sort/tests/datasets/files/smallCorrectGraph.txt"), 1},
        //{"large numeric correct graph", readGraphFromFile("../../topological_sort/tests/datasets/files/largeCorrectGraph.txt"), 1},
        //{"small cycle graph", readGraphFromFile("../../topological_sort/tests/datasets/files/smallCycleGraph.txt"), 0},
        {"large numeric cycle graph", readGraphFromFile<int>("../../topological_sort/tests/datasets/files/largeCycleGraph.txt"), 0},
        //{"star graph", readGraphFromFile("../../topological_sort/tests/datasets/files/star_graph.txt"), 1},
        //{"10000-100 graph", readGraphFromFile("../../topological_sort/tests/datasets/files/10000-100_graph.txt"), 1},
        //{"10000-5000 graph", readGraphFromFile("../../topological_sort/tests/datasets/files/10000-5000_graph.txt"), 1},
        //{"10000-10000 graph", readGraphFromFile("../../topological_sort/tests/datasets/files/10000-10000_graph.txt"), 1},
        //{"10000-10000 cycle graph", readGraphFromFile("../../topological_sort/tests/datasets/files/10000-10000_graph_cycle.txt"), 0},
        //{"10000-30000 graph", readGraphFromFile("../../topological_sort/tests/datasets/files/10000-30000_graph.txt"), 1},
    });
}
