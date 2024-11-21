#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include "Kan_by_Volkov.h"
#include "dfs_by_Makkoveeva.h"
#include "TaryanSort_by_Maslov.h"
#include "Demukrone_by_Balpeisov.h"


template<typename T>
using Algorithm = std::vector<T>(*)(std::unordered_map<T, std::vector<T>>&);

// объявите ваши алгоритмы ниже
// Пример:
// template<typename T>
// std::vector<T> topologicalSort_by_Belkin(std::unordered_map<T, std::vector<T>> &graph);
template<typename T>
std::vector<T> Demukrone_by_Balpeisov(std::unordered_map<T, std::vector<T>> &graph);

template<typename T>
std::vector<T> TaryanSort_by_Maslov(std::unordered_map<T, std::vector<T>> &graph);

template<typename T>
std::vector<T> Kan_by_Volkov(std::unordered_map<T, std::vector<T>> &graph);

template<typename T>
std::vector<T> dfs_by_Makkoveeva(std::unordered_map<T, std::vector<T>> &graph);
