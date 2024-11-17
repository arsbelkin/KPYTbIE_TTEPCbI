#include "algorithms.h"
#include <unordered_map>
#include<vector>
#include <iostream>

using namespace std;


vector<string> dfs_by_Makkoveeva(unordered_map<string, vector<string>> &graph) 
{
	vector<string>sortedgraph;
	unordered_map<string, int>visited;
	vector<string>nodes;
	for (auto& pair:graph)
	{
		nodes.push_back(pair.first);
	}
	for (string& node:nodes)
	{
		if (visited[node] == 0)
		{
			vector<string>path;
			unordered_map<string, int>currentpath;
			path.push_back(node);
			currentpath[node] = 1;
			while (!path.empty())
			{
				string currentnode = path.back();
				if (visited[currentnode] == 1)
				{
					return { " - 1" };
				}
				if (visited[currentnode] == 0)
				{
					visited[currentnode] = 1;
					for (string& neighbor : graph[currentnode])
					{
						if (visited[neighbor] == 0)
						{
							path.push_back(neighbor);
							currentpath[neighbor] = 1;
						}
					}
				}
				if (currentpath[currentnode] == 1)
				{
					currentpath[currentnode] = 2;
					sortedgraph.push_back(currentnode);
					path.pop_back();
				}
			}
		}
	}
	reverse(sortedgraph.begin(), sortedgraph.end());
	return sortedgraph;
}
