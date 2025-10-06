

import numpy as np

from ant_colony import AntColony

# making a city with 5 streets

small_distances = np.array([[np.inf, 2, 2, 5, 7, 4],
                            [2, np.inf, 4, 8, 2, 3],
                            [2, 4, np.inf, 1, 3, 6],
                            [5, 8, 1, np.inf, 2, 8],
                            [7, 2, 3, 2, np.inf, 1],
                            [4, 3, 6, 8, 1, np.inf]])

small_ant_colony = AntColony(
    small_distances, 5, 2, 10, 0.95, alpha=1, beta=1)
small_ant_colony.run()
