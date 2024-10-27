#pragma once
#include <unordered_map>

//функция для считывая графа из файла
std::unordered_map<std::string, std::vector<std::string>> readGraphFromFile(
    const std::string &path_to_file
);
