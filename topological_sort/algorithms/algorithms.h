#pragma once
#include <vector>
#include <string>
#include <unordered_map>


using Algorithm = std::vector<std::string>(*)(std::unordered_map<std::string, std::vector<std::string>>&);


std::vector<std::string> Kan_by_Volkov(std::unordered_map<std::string, std::vector<std::string>>& graph);
