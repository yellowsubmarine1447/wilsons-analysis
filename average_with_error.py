TRIALS = 100

from subprocess import check_output
from os import system
import statistics
import sys

def get_mean_and_stdev(algo, graph_type):
    values = []
    system(f"g++ {graph_type} {algo} {sys.argv[1]}")

    for _ in range(TRIALS):
        values.append(int(check_output(["./a.out",  "900"])))

    return statistics.mean(values), statistics.stdev(values)


if len(sys.argv) < 2:
    print("please provide a c++ file counting some attribute of a tree")
    exit(1)

if len(sys.argv) == 3:
    graph_type = sys.argv[2]
else:
    graph_type = "maze_graph.cpp"

mean, stdev = get_mean_and_stdev("wilsons_algo.cpp", graph_type)
print(f"Wilsons: {mean} ± {stdev}")

mean, stdev = get_mean_and_stdev("naive_ust.cpp", graph_type)
print(f"Randomised Kruskal's: {mean} ± {stdev}")