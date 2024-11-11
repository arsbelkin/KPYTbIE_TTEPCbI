#pragma once
#include <vector>
#include <string>
#include <unordered_map>


using Algorithm = std::vector<std::string>(*)(std::unordered_map<std::string, std::vector<std::string>>&);

// объявите ваши алгоритмы ниже
// Пример:
// std::vector<std::string> topologicalSort_by_Belkin(std::unordered_map<std::string, std::vector<std::string>> &graph);
std::vector<std::string> Demukrone_by_Balpeisov(std::unordered_map<std::string, std::vector<std::string>>& graph);
