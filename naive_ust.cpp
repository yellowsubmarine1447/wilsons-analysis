#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define FILE "tree.txt"

using namespace std;

int c = 0; // not really applicable here but whatever

void dfs(int u, vector<int> &next, vector<vector<int>> &tree_adj, int parent=-1) {
    for (int child : tree_adj[u]) {
        if (child == parent) {
            continue;
        }

        dfs(child, next, tree_adj, u);
    }

    next[u] = parent;
}

vector<int> random_tree_with_root(int N, int r, vector<vector<int>> &adj) {
    // we DSU join
    vector<pair<int, int>> edges;
    vector<int> parent(N);
    vector<vector<int>> tree_adj(N);
    vector<int> next(N);

    for (int i = 0; i < N; i++) {
        parent[i] = i;
        next[i] = -1;
        for (int j : adj[i]) {
            edges.push_back({i, j});
        }
    }

    random_shuffle(edges.begin(), edges.end());

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
            tree_adj[v].push_back(u);
            tree_adj[u].push_back(v);
        }
    }

    dfs(r, next, tree_adj);

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