
class Tile():
    def __init__(self, x, y, z):
        self.position = [x, y, z]
        self.color = "white"
        self.adj_list = []
        self.path = []
        self.visited = False

    def __init__(self):
        self.adj_list = []
        self.path = []

    def new_adj(self, tile):
        self.adj_list.append(tile)

class Graph:
    def __init__(self):
        self.initial_tile = Tile(0, 0, 0)
        self.initial_tile.color = "silver"
        self.all_tiles = []
        self.seen_tile = {
            [0,0,0]: True
        }
    
    def new_tile(self, tile):
        self.all_tiles.append(tile)

    def clear_path(self):
        for v in self.all_tiles:
            v.path.clear()

    def bfs(self, start, end):
        Graph.clear_path()
        list = []
        list.append(start)
        visited = {}
        seen = {}
        seen[start] = True
        while not list.empty():
            node = list.pop(0)
            if not visited[node]:
                visited[node] = True
                if node == end:
                    return node.path
            for i in range(len(node.adj_list)):
                if not visited[node.adj_list[i]]:
                    list.append(node.adj_list[i])
                    seen[node.adj_list[i]] = True
                    if not node.adj_list[i]: 
                        node.adj_list[i].path.append(node)

def sharp_dist(port):
    dist = 1 #retornar distancia do sensor 
    return dist

def wall_follower():
    if (sharp_dist("right_front") > 10 and sharp_dist("right_back") > 10):
        

def check_around(m, curr_til):
    if (sharp_dist("front_left") > 10 and sharp_dist("front_right") > 10):
        next_til = Tile(curr_til.position[0] + 1, curr_til.position[1], curr_til.position[2])
        if (not m.seen[next_til.position]) and (not next_til.visited):
            m.seen[next_til.position] = True

    if (sharp_dist("back_left") > 10 and sharp_dist("back_right") > 10):
        next_til = Tile(curr_til.position[0] - 1, curr_til.position[1], curr_til.position[2])
        if (not m.seen[next_til.position]) and (not next_til.visited):
            m.seen[next_til.position] = True

    if (sharp_dist("right_front") > 10 and sharp_dist("right_back") > 10):
        next_til = Tile(curr_til.position[0], curr_til.position[1] + 1, curr_til.position[2])
        if (not m.seen[next_til.position]) and (not next_til.visited):
            m.seen[next_til.position] = True

    if (sharp_dist("left_front") > 10 and sharp_dist("left_back") > 10):
        next_til = Tile(curr_til.position[0], curr_til.position[1] - 1, curr_til.position[2])
        if (not m.seen[next_til.position]) and (not next_til.visited):
            m.seen[next_til.position] = True

if __name__ == "__main__":
    maze = Graph()
    current_tile = maze.initial_tile
    check_around(maze, current_tile)