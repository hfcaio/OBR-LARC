#include<vector>
using namespace std;

#define sharp_FR 1
#define sharp_FL 2
#define sharp_BR 3
#define sharp_BL 4
#define sharp_RF 5
#define sharp_RB 6
#define sharp_LF 7
#define sharp_LB 8

struct vertex {
	int id_vertex; //unique id for each vertex in the graph
	int position[3];
	//add other values
	vector<vertex> adj_list; //mudar
	vector<vertex> path;
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
		
		void clean_path() {
			for (int i = 0; i < n_nodes; i++) {
				id_nodes[i].path.clear();
			}
		}

		void add_conections(vertex* s, vertex* f) { //s-start f-final
			//creating a edge between two vertexes, that goes from s to f
			s->adj_list.push_back(*f);
			n_conections++;
		}
		
		vector<String> path_creator(vertex start, vector<vertex> path) {
			vector<String> ans;
			for (int i = 0; i < path.size(); i++) {
				if (start.position[0] - path[i].position[0] > 0) ans.push_back("UP");
				else if (start.position[0] - path[i].position[0] < 0) ans.push_back("DOWN");
				else if (start.position[1] - path[i].position[1] > 0) ans.push_back("RIGHT");
				else if (start.position[1] - path[i].position[1] < 0) ans.push_back("LEFT");
			}
			
			return ans;
		}

		vector<String> bfs(vertex start, vertex end) { //breath first search
			clean_path();
			vector<vertex> list; //create a queue
			list.push_back(start); //push start into the queue
			bool visited[n_nodes]; //hash map storing the id of the vertexes the where visited by the algorithm
			bool seen[n_nodes];
			for (int i = 0; i < n_nodes; i++) visited[i] = false; // starting the array visited as false
			for (int i = 0; i < n_nodes; i++) seen[i] = false; // starting the array visited as false
			while(!list.empty()) { //while there is something in the queue 
				vertex node = list[0]; //pull the first item from the queue
				list.erase(list.begin()); //remove the first item from the queue
				if(!visited[node.id_vertex]) { //if the current vertex wasn't visited
					visited[node.id_vertex] = true; //mark as visited
					//add code here
					if (node.id_vertex == end.id_vertex) {
						return path_creator(start, node.path);
					}

					Serial.print("current node = ");
					Serial.println(node.id_vertex); //print the current vertex
				} 
				for(int i = 0; i < node.adj_list.size(); i++) { //look through the current vertex adjacents
					if(!visited[node.adj_list[i].id_vertex]) { //if they were not visited
						list.push_back(node.adj_list[i]); //put it in the queue
						if (!seen[node.adj_list[i].id_vertex]) {
							seen[node.adj_list[i].id_vertex] = true;
							node.adj_list[i].path = node.path;
							node.adj_list[i].path.push_back(node);
						}
					}
				}
			}
		}
		
};

int sharp_dist (int pin) {
	int sensorValue = 0, cmValue = 0;
	sensorValue = analogRead(sensorPin);
 	cmValue = 13*pow(sensorValue * 0.0048828125 , -1);
	return cmValue;
}

void wall_follower(vertex curr) {
	if (sharp_dist(sharp_RB) < 7 && sharp_dist(sharp_RF) < 7) {
		
	}
}

void setup( ) {
	
}

void loop() {
	 
}