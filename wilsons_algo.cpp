#include <iostream>
#include <fstream>
#include <vector>

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

void display_tree(int N, vector<int> next, bool to_stdout=false) {
    if (!to_stdout) {
        ofstream out;
        out.open(FILE);
        for (int i = 0; i < N; i++) {
            out << i << ": " << next[i] << "\n";
        }
        out.close();
    } else {
        for (int i = 0; i < N; i++) {
            cout << i << ": " << next[i] << "\n";
        }
    }
}

int get_call(void) {
    return c;
}