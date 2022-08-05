#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct Tile {
    int id_Tile;
    int position[3]; //vector(x,y,z)
	int color;
	vector<Tile> adj_list;
    vector<Tile> path;
}; 

class Graph {
	public:
		int n_nodes, n_conections;
		vector<Tile> all_tiles;
        vector<Tile> seen;

		Graph() {
			n_nodes = 1;
			n_conections = 0; 
            Tile initial; // x = 0, y = 0, z = 0
            for (int i = 0; i < 3; i++) initial.position[i] = 0;
            initial.id_Tile = 1;
		}
		
		void add_conections(Tile* s, Tile* f) { //s-start f-final
			s->adj_list.push_back(*f);
			n_conections++;
		}

        void clear_path() {
            for (int i = 0; i < n_nodes; i++) {
                all_tiles[i].path.clear();
            }
        }
		
		vector<Tile> bfs(Tile start, Tile end) { 
            clear_path();
			vector<Tile> list;
			list.push_back(start);
			map<int,bool> seen_;
			while(!list.empty()) {
				Tile node = list[0];
				list.erase(list.begin());
				if(!seen_[node.id_Tile]) {
					seen_[node.id_Tile] = true;
					if (node.id_Tile == end.id_Tile) return node.path;
				}
				for(int i = 0; i < node.adj_list.size(); i++) {
					if(!seen_[node.adj_list[i].id_Tile]) {
						list.push_back(node.adj_list[i]);
                        node.adj_list[i].path.push_back(node);
					}
				}
			}
		}
};

int sharp_dist(string port);
void check_around(Graph* m);

// x:positive to the right, y:positive to the front, z:positive up

int main() {
    Graph* maze;
    check_around(maze);
}


void check_around(Graph* m) {
    if (sharp_dist("front_left") > 10 && sharp_dist("front_right") > 10) {
        
    }
}