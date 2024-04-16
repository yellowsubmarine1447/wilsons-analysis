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

void DisplayMaze(int N, vector<int> next) {
    int sqrt, m;
    for (sqrt = 0; sqrt*sqrt <= N; sqrt++);
    sqrt--;
    for (m = sqrt; N % m != 0; m--);
    int n = N / m; // nxm rectangle

    // Go around the maze, printing out first walls, then maze
    for (int i = 0; i < n; i++) {
        // Print out the border above
        for (int j = 0; j < m; j++) {
            int curr = i * m + j;
            int v = (i-1) * m + j;
            char c = (i && (next[curr] == v || next[v] == curr)) ? ' ' : '#';
            cout << "#" << c;
        }
        cout << "#\n";

        // Print out the maze row
        for (int j = 0; j < m; j++) {
            int curr = i * m + j;
            int v = i * m + j-1;
            char c = (j && (next[curr] == v || next[v] == curr)) ? ' ' : '#';
            char cell = (next[curr] == -1) ? 'R' : ' ';
            cout << c << cell;
        }
        cout << "#\n";
    }

    // Print bottom border
    for (int j = 0; j < 2*m + 1; j++) {
        cout << "#";
    }
    cout << "\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Not enough command line arguments.\n";
        cout << "Usage: " << argv[0] << " <N>\n";
        cout << "where N is the number of vertices in the graph.\n";
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


    //printf("Time taken: %.3f seconds\n", end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec) / 1e6);
    //display_tree(N, next);
    //cout << "Wrote to " << FILE << "\n";

    cout << count_leaves(N, next);
    // cout << "Number of leaves: " << count_leaves(N, next) << '\n';
    // DisplayMaze(N, next);
}
