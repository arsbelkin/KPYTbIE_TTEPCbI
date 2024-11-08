#include <iostream>
#include "algorithms.h"
#include "../tests/DataSetRegister.h"
#include "../tests/tests_functions.h"
#include "../tests/logger.h"
#include <sstream>

using namespace std;


int main(){
    Logger logger("log.txt");
    ostringstream oss{};
    

    auto DataSets = GenerateDataSets();

    while (!DataSets.empty()){
        auto& ds = DataSets.front();

        oss << endl << endl << "***************** " << ds.description << " *****************" << endl;

        // так будет вызываться ваш алгоритм сортировки     
        // Пример:
        //RUN(topologicalSort_by_Belkin)
        //RUN(второй_алгоритм);
        //RUN(третий_алгоритм);
        RUN(TaryanSort_by_Maslov);

        DataSets.pop();

        oss << "**************************************" << endl;
    }

    logger.log(oss.str());

    return 0;
}
