#include <vector>
#include <iostream>

using namespace std;


// n >= 4 pls
vector<vector<int>> create_graph(int N) {
    vector<vector<int>> adj(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) {
                adj[i].push_back(j);
            }
        }
    }
}