#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include "Kan_by_Volkov.h"

template<typename T>
using Algorithm = std::vector<T>(*)(std::unordered_map<T, std::vector<T>>&);

// объявите ваши алгоритмы ниже
// Пример:
// std::vector<std::string> topologicalSort_by_Belkin(std::unordered_map<std::string, std::vector<std::string>> &graph);
std::vector<std::string> Demukrone_by_Balpeisov(std::unordered_map<std::string, std::vector<std::string>>& graph);
std::vector<std::string> TaryanSort_by_Maslov(std::unordered_map<std::string, std::vector<std::string>>& graph);

template<typename T>
std::vector<T> Kan_by_Volkov(std::unordered_map<T, std::vector<T>>& graph);

std::vector<std::string> dfs_by_Makkoveeva(std::unordered_map<std::string, std::vector<std::string>> &graph);
