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
	stack<string>s;
	for (auto& pair:graph)
	{
		const string& node=pair.first;
		if (visited[node] == 0)
		{
			s.push(node);
			while (!s.empty())
			{
				string currentnode = s.top();
				if (visited[currentnode] == 0)
				{
					visited[currentnode] = 1;
					for (string& neighbor : graph[currentnode])
					{
						if (visited[neighbor] == 0)
						{
							s.push(neighbor);
						}
						else if (visited[neighbor])
						{
							return { "-1" };
						}
					}
				}
				else if (visited[currentnode] == 1)
				{
					visited[currentnode] = 2;
					sortedgraph.push_back(currentnode);
					s.pop();
				}
			}
		}
	}
	reverse(sortedgraph.begin(),sortedgraph.end());
	return sortedgraph;
}
