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
    
    oss << "~~~~~~~~~~~~String data sets~~~~~~~~~~~~" << std::endl;

    auto StrDataSets = GenerateStringDataSets();

    while (!StrDataSets.empty()){
        auto& ds = StrDataSets.front();

        oss << endl << endl << "***************** " << ds.description << " *****************" << endl;

        // так будет вызываться ваш алгоритм сортировки     
        // Пример:
        //RUN(topologicalSort_by_Belkin<string>)
        //RUN(второй_алгоритм);
        //RUN(третий_алгоритм);
        RUN(Demukrone_by_Balpeisov<string>);
        RUN(TaryanSort_by_Maslov<string>);
        RUN(Kan_by_Volkov<string>);
        RUN(dfs_by_Makkoveeva<string>);

        StrDataSets.pop();

        oss << "**************************************" << endl;
    }

    oss << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

    oss << std::endl;

    oss << "~~~~~~~~~~~~Int data sets~~~~~~~~~~~~" << std::endl;

    auto IntDataSets = GenerateIntDataSets();

    while (!IntDataSets.empty()){
        auto& ds = IntDataSets.front();

        oss << endl << endl << "***************** " << ds.description << " *****************" << endl;

        // так будет вызываться ваш алгоритм сортировки     
        // Пример:
        //RUN(topologicalSort_by_Belkin<int>)
        //RUN(второй_алгоритм);
        //RUN(третий_алгоритм);
        RUN(Demukrone_by_Balpeisov<int>);
        RUN(TaryanSort_by_Maslov<int>);
        RUN(Kan_by_Volkov<int>);
        RUN(dfs_by_Makkoveeva<int>);

        IntDataSets.pop();

        oss << "**************************************" << endl;
    }

    oss << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;


    logger.log(oss.str());

    return 0;
}
