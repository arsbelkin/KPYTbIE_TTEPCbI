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
    

    auto StrDataSets = GenerateStringDataSets();

    while (!StrDataSets.empty()){
        auto& ds = StrDataSets.front();

        oss << endl << endl << "***************** " << ds.description << " *****************" << endl;

        // так будет вызываться ваш алгоритм сортировки     
        // Пример:
        //RUN(topologicalSort_by_Belkin)
        //RUN(второй_алгоритм);
        //RUN(третий_алгоритм);
        //RUN(Demukrone_by_Balpeisov);
        //RUN(TaryanSort_by_Maslov);
        RUN(Kan_by_Volkov<string>);
        //RUN(dfs_by_Makkoveeva);

        StrDataSets.pop();

        oss << "**************************************" << endl;
    }


    auto IntDataSets = GenerateIntDataSets();

    while (!IntDataSets.empty()){
        auto& ds = IntDataSets.front();

        oss << endl << endl << "***************** " << ds.description << " *****************" << endl;

        // так будет вызываться ваш алгоритм сортировки     
        // Пример:
        //RUN(topologicalSort_by_Belkin)
        //RUN(второй_алгоритм);
        //RUN(третий_алгоритм);
        //RUN(Demukrone_by_Balpeisov);
        //RUN(TaryanSort_by_Maslov);
        RUN(Kan_by_Volkov<int>);
        //RUN(dfs_by_Makkoveeva);

        IntDataSets.pop();

        oss << "**************************************" << endl;
    }


    logger.log(oss.str());

    return 0;
}
