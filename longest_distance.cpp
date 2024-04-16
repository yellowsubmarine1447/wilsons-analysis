#include <iostream>
#include "random_tree.h"
#include "graph.h"
#include <sys/time.h>
#include <vector>

using namespace std;

int dfs(int child, vector<vector<int>> &adj, int &m, int parent=-1) {
    int largest_depth = 0;
    int second_largest =  0;

    for (int u : adj[child]) {
        if (u == parent) {
            continue;
        }

        int new_depth = dfs(u, adj, m, child);
        if (new_depth > largest_depth) {
            second_largest = largest_depth;
            largest_depth = new_depth;
        } else if (new_depth > second_largest) {
            second_largest = new_depth;
        }
    }

    m = max(m, largest_depth + second_largest);

    return largest_depth + 1;
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
    int m = 0;
    int root = N-1; // can make random
    vector<vector<int>> adj(N);

    vector<vector<int>> graph_adj = create_graph(N);

    //gettimeofday(&start, NULL);
    vector<int> next = random_tree_with_root(N, root, graph_adj);
    //gettimeofday(&end, NULL);

    //printf("Time taken: %.3f seconds\n", end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec) / 1e6);
    //display_tree(N, next);
    //cout << "Wrote to " << FILE << "\n";
    for (int i = 0; i < N; i++) {
        if (next[i] == -1) {
            continue;
        }

        adj[next[i]].push_back(i);
        adj[i].push_back(next[i]);
    }

    dfs(root, adj, m);

    cout << m;
}