#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct vertex {
	int id_vertex; //unique id for each vertex in the graph
	//add other values
	vector<vertex> adj_list; //the list with all vertex adjacent of the current vertex
}; 

class Graph {
	public:
		int n_nodes, n_conections; //n_nodes: number of nodes in the graph, n_conections: number of conections in the graph
		vertex* id_nodes; //an array with all vertexes in the graph
	
		Graph() { //std constructor
			n_nodes = 0;
			n_conections = 0; 
		}
		
		Graph(int initial_nodes) { //constructor passing the number of vertexs
			n_nodes = initial_nodes;
			n_conections = 0; 
		}
		
		void add_conections(vertex* s, vertex* f) { //s-start f-final
			//creating a edge between two vertexes, that goes from s to f
			s->adj_list.push_back(*f);
			n_conections++;
		}
		
		void bfs(vertex start) { //breath first search
			vector<vertex> list; //create a stack
			list.push_back(start); //push start into the stack
			map<int,bool> seen; //hash map storing the id of the vertexes the where visited by the algorithm 
			while(!list.empty()) { //while there is something in the stack 
				vertex node = list[0]; //pull the first item from the stack
				list.erase(list.begin()); //remove the first item from the stack
				if(!seen[node.id_vertex]) { //if the current vertex wasn't visited
					seen[node.id_vertex] = true; //mark as visited
					//add code here
					cout << node.id_vertex << "\n"; //print the current vertex
				} 
				for(int i = 0; i < node.adj_list.size(); i++) { //look through the current vertex adjacents
					if(!seen[node.adj_list[i].id_vertex]) { //if they were not visited
						list.push_back(node.adj_list[i]); //put it in the stack
					}
				}
			}
		}
		
		void dfs(vertex start) { //depth first search
			vector<vertex> list; //create a stack
			list.push_back(start); //push start into the stack
			map<int,bool> seen; //hash map storing the id of the vertexes the where visited by the algorithm 
			while(!list.empty()) { //while there is something in the stack 
				vertex node = list[list.size() - 1]; //pull the last item from the stack
				list.erase(list.end()); //remove the last item from the stack
				if(!seen[node.id_vertex]) { //if the current vertex wasn't visited
					seen[node.id_vertex] = true; //mark as visited
					//add code here
					cout << node.id_vertex << "\n"; //print the current vertex
				}
				for(int i = 0; i < node.adj_list.size(); i++) { //look through the current vertex adjacents
					if(!seen[node.adj_list[i].id_vertex]) { //if they were not visited
						list.push_back(node.adj_list[i]); //put it in the stack
					}
				}
			}
		}
};

int n;
int ans;

void solve( ) {
	
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(0);
	cin >> n;
	 
}
