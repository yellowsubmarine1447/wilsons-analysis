#include <iostream>
#include "random_tree.h"
#include "graph.h"
#include <sys/time.h>

using namespace std;

// Count number of leaves
int count_leaves(int N, vector<int> next) {
    vector<bool> leaves(N, true);
    for (int i = 0; i < N; i++) {
        leaves[next[i]] = false;
    }

    int leaf_count = 0;
    for (int i = 0; i < N; i++) {
        leaf_count += leaves[i];
    }

    return leaf_count;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Not enough command line arguments.\n";
        cout << "Usage: " << argv[0] << " <N>\n";
        cout << "where N is the number of vertices in the graph (preferably a multiple of 4).\n";
        return 1;
    }

    // Initialise seed
    struct timeval t, start, end;
    gettimeofday(&t, NULL);
    srand((unsigned) t.tv_usec);

    // Initialise N, next
    int N = stoi(argv[1]);

    vector<vector<int>> graph_adj = create_graph(N);

    //gettimeofday(&start, NULL);
    // Randomly choose a root
    int r = rand() % N;
    vector<int> next = random_tree_with_root(N, r, graph_adj);
    //gettimeofday(&end, NULL);

    cout << "Number of leaves: " << count_leaves(N, next) << '\n';

    //printf("Time taken: %.3f seconds\n", end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec) / 1e6);
    //display_tree(N, next);
    //cout << "Wrote to " << FILE << "\n";
    display_tree(N, next, true);
}
