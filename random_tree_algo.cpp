#include <iostream>
#include <fstream>
#include "graph.h"
#include <sys/time.h>

#define FILE "tree.txt"

using namespace std;

int c = 0;

// Gets a random adjacent vertex
int random_successor(int u, vector<vector<int>> &adj) {
    c++;
    int s = adj[u].size();
    return adj[u][rand() % s];
}

vector<int> random_tree_with_root(int N, int r, vector<vector<int>> &adj) {
    bool in_tree[N];
    fill(in_tree, in_tree+N, false);
    vector<int> next(N);

    next[r] = -1;
    in_tree[r] = true;

    for (int i = 0; i < N; i++) {
        int u = i;
        while (!in_tree[u]) {
            next[u] = random_successor(u, adj);
            u = next[u];
        }

        u = i;
        while (!in_tree[u]) {
            in_tree[u] = true;
            u = next[u];
        }
    }

    return next;
}

void display_tree(int N, vector<int> next) {
    ofstream out;
    out.open(FILE);
    out << "Calls to random_successor: " << c << "\n";
    for (int i = 0; i < N; i++) {
        out << i << ": " << next[i] << "\n";
    }
    out.close();
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

    gettimeofday(&start, NULL);
    vector<int> next = random_tree_with_root(N, N-1, graph_adj);
    gettimeofday(&end, NULL);

    //printf("Time taken: %.3f seconds\n", end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec) / 1e6);
    //display_tree(N, next);
    //cout << "Wrote to " << FILE << "\n";
    cout << c;
}