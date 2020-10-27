#include <iostream>
#include <string>
#include <unordered_map>
#include <limits.h>
#include <unordered_set>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

// must have a depth-first search helper function in here
auto dfs(std::unordered_map<std::string, std::vector<std::string>> &graph, std::string current,
		 std::string destination, std::vector<std::string> visited, 
		 bool &found, std::vector<std::string> &path) -> void {
	// found a cycle
	if (std::find(visited.begin(), visited.end(), current) != visited.end()) {
	    return;
	}
	
	visited.push_back(current);
	
	if (current == destination)	{
		found = true;
		if (path.size() > visited.size())	{
			path = visited;
		}
		return;
	}

    std::vector<std::string> network = graph[current];
    
	for (auto neighbor : network)	{
		dfs(graph, neighbor, destination, visited, found, path);
	}
}

vector<string> getPath(unordered_map<string, vector<string>> graph,
                       const string &startNode, const string &endNode) {
    // find the shortest route in the network between the two users
    if (graph.empty())
        throw "Graph is empty";
    else if (graph.count(startNode) == 0)
        throw "Cannot find the startNode";
    else if (graph.count(endNode) == 0)
        throw "Cannot find the endNode";
    else if (startNode == endNode)
    	return std::vector<std::string>();

    std::vector<std::string> path = {startNode};

    bool found{false};

    std::vector<std::string> visited = {startNode};

    std::vector<std::string> neighbors = graph[startNode];
    for (std::string neighbor : neighbors) {
    	dfs(graph, neighbor, endNode, visited, found, path);
    }

    return found ? path : std::vector<std::string>();
}