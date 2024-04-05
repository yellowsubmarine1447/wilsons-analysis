#include <vector>
#include <iostream>

using namespace std;


// please give me one with a nice factor lmao, square preferrable
vector<vector<int>> create_graph(int N) {
    int sqrt, m;
    for (sqrt = 0; sqrt*sqrt <= N; sqrt++);
    sqrt--;
    for (m = sqrt; N % m != 0; m--);
    int n = N / m; // n \times m rectangle
    vector<vector<int>> adj(N);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int u = i * m + j;
            if (i != 0) {
                adj[u].push_back((i-1)*m + j);
            }
            if (i != n-1) {
                adj[u].push_back((i+1)*m + j);
            }
            if (j != 0) {
                adj[u].push_back(i*m + j - 1);
            }
            if (j != m-1) {
                adj[u].push_back(i*m + j + 1);
            }
        }
    }

    return adj;
}