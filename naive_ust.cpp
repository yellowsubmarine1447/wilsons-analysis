#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define FILE "tree.txt"

using namespace std;

int c = 0; // not really applicable here but whatever


vector<int> random_tree_with_root(int N, int r, vector<vector<int>> &adj) {
    // we DSU join
    
    vector<int> edges;
    vector<int> parent(N);
    for (int i : adj) {
        parent[i] = i;
        for (int j : adj[i]) {
            edges.push_back({i, j});
        }
    }

    random_shuffle(edges);

    for (pair<int, int> edge : edges) {
        int u = edge.first; int v = edge.second;
        int s = u;
        int t = v;
        while (s != parent[s] && t != parent[t]) {
            s = parent[s];
            t = parent[t];
        }

        if (t != parent[t]) { // t is taller
            swap(s, t);
            swap(u, v);
        }

        while (s != parent[s]) {
            s = parent[s];
        }

        if (s != t) {
            parent[t] = s; // dsu join
            next[v] = u; // edge join
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