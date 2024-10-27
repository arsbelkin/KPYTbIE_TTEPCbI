#pragma once
#include <unordered_map>


std::unordered_map<std::string, std::vector<std::string>> readGraphFromFile(
    const std::string &path_to_file
);
