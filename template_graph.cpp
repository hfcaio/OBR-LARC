#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct vertex {
	int id_vertex; //unique id for each vertex in the graph
	int position[3];
	//add other values
	vector<vertex> adj_list; //mudar
	vector<vertex> path;
}; 

class Graph
{
public:
	int n_nodes, n_conections; // n_nodes: number of nodes in the graph, n_conections: number of conections in the graph
	vertex *id_nodes;		   // an array with all vertexes in the graph

	Graph()
	{ // std constructor
		n_nodes = 0;
		n_conections = 0;
	}

	Graph(int initial_nodes)
	{ // constructor passing the number of vertexs
		n_nodes = initial_nodes;
		n_conections = 0;
	}

	// functions
	void add_conections(vertex *s, vertex *f);
	void bfs(vertex start);
	void dfs(vertex start);
	void clean_path();
	vector<string> bfs_path(vertex start, vertex end);
	vector<string> path_creator(vertex start, vector<vertex> path);
};

void Graph::add_conections(vertex *s, vertex *f)
{ // s-start f-final
	// creating a edge between two vertexes, that goes from s to f
	s->adj_list.push_back(*f);
	n_conections++;
}

void Graph::bfs(vertex start)
{						   // breath first search
	vector<vertex> list;   // create a stack
	list.push_back(start); // push start into the stack
	map<int, bool> seen;   // hash map storing the id of the vertexes the where visited by the algorithm
	while (!list.empty())
	{							  // while there is something in the stack
		vertex node = list[0];	  // pull the first item from the stack
		list.erase(list.begin()); // remove the first item from the stack
		if (!seen[node.id_vertex])
		{								 // if the current vertex wasn't visited
			seen[node.id_vertex] = true; // mark as visited
			// add code here
			cout << node.id_vertex << "\n"; // print the current vertex
		}
		for (int i = 0; i < node.adj_list.size(); i++)
		{ // look through the current vertex adjacents
			if (!seen[node.adj_list[i].id_vertex])
			{									  // if they were not visited
				list.push_back(node.adj_list[i]); // put it in the stack
			}
		}
	}
}

void Graph::dfs(vertex start)
{						   // depth first search
	vector<vertex> list;   // create a stack
	list.push_back(start); // push start into the stack
	map<int, bool> seen;   // hash map storing the id of the vertexes the where visited by the algorithm
	while (!list.empty())
	{										 // while there is something in the stack
		vertex node = list[list.size() - 1]; // pull the last item from the stack
		list.erase(list.end());				 // remove the last item from the stack
		if (!seen[node.id_vertex])
		{								 // if the current vertex wasn't visited
			seen[node.id_vertex] = true; // mark as visited
			// add code here
			cout << node.id_vertex << "\n"; // print the current vertex
		}
		for (int i = 0; i < node.adj_list.size(); i++)
		{ // look through the current vertex adjacents
			if (!seen[node.adj_list[i].id_vertex])
			{									  // if they were not visited
				list.push_back(node.adj_list[i]); // put it in the stack
			}
		}
	}
}

void Graph::clean_path()
{
	for (int i = 0; i < n_nodes; i++)
	{
		id_nodes[i].path.clear();
	}
}

vector<string> Graph::path_creator(vertex start, vector<vertex> path)
{
	vector<string> ans;
	for (int i = 0; i < path.size(); i++)
	{
		if (start.position[0] - path[i].position[0] > 0)
			ans.push_back("UP");
		else if (start.position[0] - path[i].position[0] < 0)
			ans.push_back("DOWN");
		else if (start.position[1] - path[i].position[1] > 0)
			ans.push_back("RIGHT");
		else if (start.position[1] - path[i].position[1] < 0)
			ans.push_back("LEFT");
	}

	return ans;
}

vector<vector> Graph::bfs_path(vertex start, vertex end)
{
	this->clean_path();
	vector<vertex> list;   // create a queue
	list.push_back(start); // push start into the queue
	bool visited[n_nodes]; // hash map storing the id of the vertexes the where visited by the algorithm
	bool seen[n_nodes];
	for (int i = 0; i < n_nodes; i++)
		visited[i] = false; // starting the array visited as false
	for (int i = 0; i < n_nodes; i++)
		seen[i] = false; // starting the array visited as false
	while (!list.empty())
	{							  // while there is something in the queue
		vertex node = list[0];	  // pull the first item from the queue
		list.erase(list.begin()); // remove the first item from the queue
		if (!visited[node.id_vertex])
		{									// if the current vertex wasn't visited
			visited[node.id_vertex] = true; // mark as visited
			// add code here
			if (node.id_vertex == end.id_vertex)
			{
				return this->path_creator(start, node.path);
			}

			cout << "current node: " <<node.id_vertex << "\n"; // print the current vertex
		}
		for (int i = 0; i < node.adj_list.size(); i++)
		{ // look through the current vertex adjacents
			if (!visited[node.adj_list[i].id_vertex])
			{									  // if they were not visited
				list.push_back(node.adj_list[i]); // put it in the queue
				if (!seen[node.adj_list[i].id_vertex])
				{
					seen[node.adj_list[i].id_vertex] = true;
					node.adj_list[i].path = node.path;
					node.adj_list[i].path.push_back(node);
				}
			}
		}
	}
}

int n;
int ans;

void solve()
{
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
}
