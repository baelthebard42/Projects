import numpy as np
import matplotlib.pyplot as plt
import networkx as nx
import itertools

class AntColony:
    def __init__(self, distances, coordinates, n_ants=30, n_iterations=300, alpha=1, beta=2, evaporation=0.5, Q=1):
        self.distances = distances
        self.coordinates = coordinates
        self.n_cities = distances.shape[0]
        self.n_ants = n_ants
        self.n_iterations = n_iterations
        self.alpha = alpha
        self.beta = beta
        self.evaporation = evaporation
        self.Q = Q
        self.pheromones = np.ones((self.n_cities, self.n_cities))

    def run(self):
        best_path = None
        best_length = float("inf")

        for _ in range(self.n_iterations):
            paths, lengths = self._construct_solutions()
            self._update_pheromones(paths, lengths)

            min_length = min(lengths)
            if min_length < best_length:
                best_length = min_length
                best_path = paths[np.argmin(lengths)]

        return best_path, best_length

    def _construct_solutions(self):
        paths, lengths = [], []
        for _ in range(self.n_ants):
            path = self._construct_path()
            length = self._path_length(path)
            paths.append(path)
            lengths.append(length)
        return paths, lengths

    def _construct_path(self):
        path = [0] 
        for _ in range(self.n_cities - 1):
            current_city = path[-1]
            next_city = self._select_next_city(current_city, path)
            path.append(next_city)
        return path + [0] 

    def _select_next_city(self, current_city, path):
        unvisited = list(set(range(self.n_cities)) - set(path))
        pheromone = self.pheromones[current_city, unvisited]
        heuristic = 1 / self.distances[current_city, unvisited]
        probabilities = (pheromone ** self.alpha) * (heuristic ** self.beta)
        probabilities /= probabilities.sum()
        return np.random.choice(unvisited, p=probabilities)

    def _path_length(self, path):
        return sum(self.distances[path[i], path[i + 1]] for i in range(len(path) - 1))

    def _update_pheromones(self, paths, lengths):
        self.pheromones *= (1 - self.evaporation)
        for path, length in zip(paths, lengths):
            for i in range(len(path) - 1):
                self.pheromones[path[i], path[i + 1]] += self.Q / length
                self.pheromones[path[i + 1], path[i]] += self.Q / length

    def brute_force_tsp(self):
        best_path = None
        best_length = float("inf")
        cities = list(range(1, self.n_cities))
        
        for perm in itertools.permutations(cities):
            path = [0] + list(perm) + [0]
            length = self._path_length(path)
            if length < best_length:
                best_length = length
                best_path = path
        
        return best_path, best_length

    def visualize(self, best_path, best_length, optimal_path, optimal_length):
        fig, ax = plt.subplots(1, 2, figsize=(14, 6))
        G = nx.Graph()
        
        for i, (x, y) in enumerate(self.coordinates):
            G.add_node(i, pos=(x, y))
        
        pos = nx.get_node_attributes(G, 'pos')
        ax[0].scatter(*zip(*pos.values()), c='red', s=100)
        for i, (x, y) in pos.items():
            ax[0].text(x, y, f'{i}', fontsize=12, verticalalignment='bottom')
        ax[0].set_title("Initial City Locations")
        ax[0].grid(True)

        edges_best = [(best_path[i], best_path[i+1]) for i in range(len(best_path) - 1)]
        edges_optimal = [(optimal_path[i], optimal_path[i+1]) for i in range(len(optimal_path) - 1)]
        
        nx.draw(G, pos, ax=ax[1], with_labels=True, node_color='red', node_size=500, font_size=12)
        nx.draw_networkx_edges(G, pos, edgelist=edges_best, ax=ax[1], edge_color='blue', width=2, label=f"ACO Path: {best_length:.2f}")
        nx.draw_networkx_edges(G, pos, edgelist=edges_optimal, ax=ax[1], edge_color='green', width=2, style='dashed', label=f"Optimal Path: {optimal_length:.2f}")

        ax[1].set_title("ACO vs Optimal Path")
        ax[1].legend()
        plt.show()

if __name__ == "__main__":
    np.random.seed()
    coordinates = np.random.randint(0, 50, size=(10, 2))  # 10 cities
    n = len(coordinates)
    distances = np.zeros((n, n))
    for i in range(n):
        for j in range(n):
            distances[i, j] = np.linalg.norm(coordinates[i] - coordinates[j])

    colony = AntColony(distances, coordinates, n_ants=30, n_iterations=300)
    best_path, best_length = colony.run()
    optimal_path, optimal_length = colony.brute_force_tsp()
    
    print("ACO Best Path:", best_path)
    print("ACO Best Path Length:", best_length)
    print("Optimal Path:", optimal_path)
    print("Optimal Path Length:", optimal_length)
    
    colony.visualize(best_path, best_length, optimal_path, optimal_length)