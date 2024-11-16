#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include "algorithms.h"

using namespace std;


std::vector<std::string> Kan_by_Volkov(std::unordered_map<std::string, std::vector<std::string>>& graph)
{
	std::unordered_map<std::string, int> inDegree;

	for (const auto& pair : graph) {
		const std::string& vertex = pair.first;
		inDegree[vertex] = 0;
	}

	for (const auto& pair : graph) {
		const std::string& vertex = pair.first;
		for (const std::string& neighbor : pair.second) {
			inDegree[neighbor]++;
		}
	}

	std::queue<std::string> zero;

	for (const auto& pair : inDegree) {
		if (pair.second == 0) {
			zero.push(pair.first);
		}
	}

	std::vector<std::string> sort;
	while (!zero.empty()) {
		std::string vertex = zero.front();
		zero.pop();
		sort.push_back(vertex);

		for (const std::string& neighbor : graph.at(vertex)) {
			inDegree[neighbor]--;
			if (inDegree[neighbor] == 0) {
				zero.push(neighbor);
			}
		}
	}

	if (sort.size() != inDegree.size()) {
		return { "-1" };
	}

	else {
		return sort;
	}
}