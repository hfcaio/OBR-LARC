#include<bits/stdc++.h>
#include<iostream>
using namespace std;



	/*
	1 1 1 1 1 1 1 1 1 1
	1 0 0 0 0 0 0 0 0 1
	1 0 0 0 0 0 0 0 0 1
	1 0 0 0 0 0 0 0 0 1
	1 0 0 0 0 0 0 0 0 1
	1 0 0 0 0 0 0 0 0 1
	1 0 0 0 0 0 0 0 0 1
	1 0 0 0 0 0 0 0 0 1
	1 0 0 0 0 0 0 0 0 1
	1 1 1 1 1 1 1 1 1 1
	*/

class Tile {
	char color;
	bool visited = 0;
	int x,y;
	vector<Tile> adj; 
	vector<Tile> path;
}

class Maze {
	vector<Tile> maze;
	Tile start_tile;
	start_tile.x = 0;
	start_tile.y = 0;

	//functions

	void reset_maze() {
		for(int i = 0; i < maze.size; i++) {
			maze[i].visited = 0;
			maze[i].path.erased(maze[i].path.begin(), maze[i].path.end());
		}
	}

	vector<Tile> bfs(Tile s, Tile e) {
		reset_maze();
		deque<Tile> queue;
		vector<Tile> path;

		queue.push_back(s);

		while(queue.size()) {
			Tile cur_tile = queue.pop_front();
			cur_tile.visited = 1;

			if (cur_tile == e) {
				path = cur_tile.path;
				break;
			}

			for (int i = 0; i < cur_tile.adj.size(); i++) {
				if (!cur_tile.adj[i].visited) {
					queue.push_back(cur_tile.adj[i]);
					cur_tile.adj[i].path.push_back(cur_tile);
				}
			}
		}

		return path;
	}
}


int main() {
	const int l = 10, m = 10;
	int g[l][m];

	Maze maze;
	maze.maze = malloc(sizeof(Tile) * l * m);

	for (int i = 0; i < l; i++) {
		for (int j = 0; j < m; j++) {
			cin << g[i][j];
		}
	}
}
