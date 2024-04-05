from subprocess import check_output
from os import system
dist = {}
TRIALS = 1000

system("g++ show_tree.cpp random_tree_algo.cpp complete_graph.cpp")
for _ in range(TRIALS):
    result = check_output(["./a.out", "5"])
    if result not in dist:
        dist[result] = 0
    dist[result] += 1

print(dist.values())