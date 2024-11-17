#include "algorithms.h"
#include <unordered_map>
#include<vector>
#include <iostream>
#include <string>
#include<stack>
#include <algorithm>

using namespace std;

vector<string> dfs_by_Makkoveeva(unordered_map<string, vector<string>> &graph) 
{
	vector<string>sortedgraph;
	unordered_map<string, int>visited;
	vector<string>stack;
	bool cycle = false;
	for (auto& pair:graph)
	{
		const string& node=pair.first;
		if (visited[node] == 0)
		{
			stack.push_back(node);
			while (!stack.empty()&&!cycle)
			{
				string currentnode = stack.back();
				stack.pop_back();
				if (visited[currentnode] == 0)
				{
					visited[currentnode] = 1;
					stack.push_back(currentnode);
					for (const string& neighbor : graph[currentnode])
					{
						if (visited[neighbor] == 0)
						{
							stack.push_back(neighbor);
						}
						else if (visited[neighbor]==1)
						{
							cycle=true;
							break;
						}
					}
				}
				else if (visited[currentnode] == 1)
				{
					visited[currentnode] = 2;
					sortedgraph.push_back(currentnode);
				}
			}
			if (cycle)
			{
				return { "-1" };
			}
		}
	}
	reverse(sortedgraph.begin(),sortedgraph.end());
	return sortedgraph;
}
