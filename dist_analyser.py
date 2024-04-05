from subprocess import check_output
from os import system
from sys import argv

dist = {}
TRIALS = 1000

if len(argv) < 2:
    print("please provide algorithm file which will be run against distribution analyser")
    exit(1)

if len(argv) < 3:
    graph_type = "complete_graph.cpp"
else:
    graph_type = argv[2]

if len(argv) < 4:
    size = "5"
else:
    size = argv[3]

system(f"g++ show_tree.cpp {argv[1]} {graph_type}")
for _ in range(TRIALS):
    result = check_output(["./a.out", size])
    if result not in dist:
        dist[result] = 0
    dist[result] += 1

print(dist.values())