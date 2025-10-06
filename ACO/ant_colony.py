import random as rn
import numpy as np
from numpy.random import choice as np_choice
import matplotlib.animation as ani
import matplotlib.pyplot as plt
import matplotlib.colors as col
import time


class AntColony(object):

    def __init__(self, distances, n_ants, n_best, n_iterations, decay, alpha=1, beta=1, graph=True):
        """
        distances : Square matrix of distances
        n_ants : Number of ants running per iteration
        n_best : Number of ants who deposit pheromone
        n_iteration : Number of iterations
        decay : Rate at which pheromone decays.
        alpha (int or float): pheromone weight higher=more pheromones
        beta (int or float): exponent on distance, higher beta give distance more weight        
        """
        self.distances = distances
        self.pheromone = np.ones(self.distances.shape) / \
            len(distances)  # initializing all to 1/d
        self.all_inds = range(len(distances))
        self.n_ants = n_ants
        self.n_best = n_best
        self.n_iterations = n_iterations
        self.decay = decay
        self.alpha = alpha
        self.beta = beta
        self.graph = graph
        # for graph
        if(graph):
            self.color = list(col.TABLEAU_COLORS.keys())[:n_ants]
            self.fig = plt.figure()
            self.x = [i+1 for i in range(n_iterations)]
            self.y = np.zeros((n_iterations, n_ants))
            plt.ylabel('Path distance')
            plt.xlabel('Iteration')
            plt.ylim()
            plt.grid(True)

    def run(self):
        shortest_path = None
        for i in range(self.n_iterations):
            all_paths = self.gen_all_paths(i)
            self.spread_pheronome(all_paths, self.n_best,
                                  shortest_path=shortest_path)
            if(self.graph == False):
                time.sleep(3)  # for your viewing pleasure
            shortest_path = min(all_paths, key=lambda x: x[1])
            self.pheromone = self.pheromone * self.decay
        if(self.graph):
            animator = ani.FuncAnimation(
                self.fig, self.buildmebarchart, interval=100)
            plt.show()
        return all_paths[-1][1]

    def buildmebarchart(self, i=int):
        leg = ['Ant '+str(j+1) for j in range(self.n_ants)]
        plt.ylim(0, np.max(self.y)*1.1)
        plt.legend(leg)
        p = plt.plot(self.x[:i], self.y[:i])
        for k in range(self.n_ants):
            p[k].set_color(self.color[k])

    def spread_pheronome(self, all_paths, n_best, shortest_path):
        sorted_paths = sorted(all_paths, key=lambda x: x[1])
        # only the n best ants spread pheromones - darwin
        for path, dist in sorted_paths[:n_best]:
            for move in path:
                self.pheromone[move] += 1.0 / self.distances[move]
        print('spreading pheromone ...')

    def gen_path_dist(self, path):
        total_dist = 0
        for ele in path:
            total_dist += self.distances[ele]
        return total_dist

    def gen_all_paths(self, iter):
        all_paths = []
        print('\nIteration', iter)
        for i in range(self.n_ants):
            path = self.gen_path(0)
            dist = self.gen_path_dist(path)
            print('Ant', i, ' path:', path, dist)
            if(self.graph):
                self.y[iter][i] = dist
            all_paths.append((path, dist))
        return all_paths

    def gen_path(self, start):
        path = []
        visited = set()
        visited.add(start)
        prev = start
        for i in range(len(self.distances) - 1):
            # pick random node from unvisited nodes
            move = self.pick_move(
                self.pheromone[prev], self.distances[prev], visited)
            path.append((prev, move))
            prev = move
            visited.add(move)
        path.append((prev, start))  # going back to where we started
        return path

    def pick_move(self, pheromone, dist, visited):
        pheromone = np.copy(pheromone)
        pheromone[list(visited)] = 0

        # adjust pheromone level acc to weight
        row = pheromone ** self.alpha * ((1.0 / dist) ** self.beta)

        norm_row = row / row.sum()
        move = np_choice(self.all_inds, 1, p=norm_row)[
            0]  # pick 1 random index for move
        return move
