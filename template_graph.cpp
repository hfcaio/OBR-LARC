#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct vertex {
	int id_vertex;
	//colocar outro valor
	vector<vertex> adj_list;
}; 

class Graph {
	public:
		int n_nodes, n_conections;
		vertex* id_nodes;
	
		Graph() {
			n_nodes = 0;
			n_conections = 0; 
		}
		
		Graph(int initial_nodes) {
			n_nodes = initial_nodes;
			n_conections = 0; 
		}
		
		void add_conections(vertex* s, vertex* f) { //s-start f-final
			s->adj_list.push_back(*f);
			n_conections++;
		}
		
		void bfs(vertex start) { 
			vector<vertex> list;
			list.push_back(start);
			map<int,bool> seen;
			while(!list.empty()) {
				vertex node = list[0];
				list.erase(list.begin());
				if(!seen[node.id_vertex]) {
					seen[node.id_vertex] = true;
					//fazer o q quer
					cout << node.id_vertex << "\n";
				}
				for(int i = 0; i < node.adj_list.size(); i++) {
					if(!seen[node.adj_list[i].id_vertex]) {
						list.push_back(node.adj_list[i]);
					}
				}
			}
		}
		
		void dfs(vertex start) {
			vector<vertex> list;
			list.push_back(start);
			map<int,bool> seen;
			while(!list.empty()) {
				vertex node = list[list.size() - 1];
				list.erase(list.end());
				if(!seen[node.id_vertex]) {
					seen[node.id_vertex] = true;
					//fazer o q quer
					cout << node.id_vertex << "\n";
				}
				for(int i = 0; i < node.adj_list.size(); i++) {
					if(!seen[node.adj_list[i].id_vertex]) {
						list.push_back(node.adj_list[i]);
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
