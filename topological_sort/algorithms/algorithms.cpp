#include <iostream>
#include "algorithms.h"
#include "../tests/DataSetRegister.h"
#include "../tests/tests_functions.h"
#include "../tests/logger.h"
#include <sstream>

using namespace std;


static string dataset = "";
static bool can_be_sorted = 0;


int main(){
    Logger logger("log.txt");
    ostringstream oss{};
    

    auto DataSets = GenerateDataSets();

    while (!DataSets.empty()){
        auto& ds = DataSets.front();

        oss << endl << endl << "***************** " << ds.description << " *****************" << endl;

        // так будет вызываться ваш алгоритм сортировки     
        //RUN(первый_алгоритм);
        //RUN(второй_алгоритм);

        DataSets.pop();

        oss << "**************************************" << endl;
    }

    logger.log(oss.str());

    return 0;
}
