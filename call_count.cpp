#include <iostream>
#include "random_tree.h"
#include <sys/time.h>
#include "graph.h"

using namespace std;

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
    vector<int> next = random_tree_with_root(N, N-1, graph_adj);
    //gettimeofday(&end, NULL);

    //printf("Time taken: %.3f seconds\n", end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec) / 1e6);
    //display_tree(N, next);
    //cout << "Wrote to " << FILE << "\n";
    cout << get_call();
}