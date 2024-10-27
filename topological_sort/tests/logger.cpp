#include <iostream>
#include "logger.h"

using namespace std;


Logger::Logger(const std::string& filename){
    logFile.open(filename);
    if (!logFile.is_open()) {
        std::cerr << "Error opening logger file!" << std::endl;
        return;
    }
}


Logger::~Logger(){
    if (logFile.is_open()) {
        logFile.close();
    }
}


void Logger::log(const std::string &message){
    if (logFile.is_open()){
        logFile << message << endl;
    }

    cout << message << endl;
}
