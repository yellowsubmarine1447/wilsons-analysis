TRIALS = 1000

from subprocess import check_output
from os import system
import statistics
import sys

def get_mean_and_stdev(algo):
    values = []
    system(f"g++ maze_graph.cpp {algo} {sys.argv[1]}")

    for _ in range(TRIALS):
        values.append(int(check_output(["./a.out",  "1000"])))

    return statistics.mean(values), statistics.stdev(values)


if len(sys.argv) < 2:
    print("please provide a c++ file counting some attribute of a tree")
    exit(1)

mean, stdev = get_mean_and_stdev("wilsons_algo.cpp")
print(f"Wilsons: {mean} ± {stdev}")

mean, stdev = get_mean_and_stdev("naive_ust.cpp")
print(f"Randomised Kruskal's: {mean} ± {stdev}")