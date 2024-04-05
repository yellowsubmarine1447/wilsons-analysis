#include <vector>
#include <iostream>

using namespace std;


// n >= 4 pls
vector<vector<int>> create_graph(int N) {
    vector<vector<int>> adj(N);
    int chain_length = N / 4;
    adj[0].push_back(1);
    adj[N-1].push_back(N-2);
    adj[chain_length].push_back(chain_length-1);
    adj[N-chain_length-1].push_back(N-chain_length);

    for (int i = 1; i < chain_length; i++) {
        adj[i].push_back(i-1);
        adj[i].push_back(i+1);
    }

    for (int i = N - chain_length; i < N-1; i++) {
        adj[i].push_back(i-1);
        adj[i].push_back(i+1);
    }

    for (int i = chain_length; i < N - chain_length; i++) {
        for (int j = chain_length; j < N - chain_length; j++) {
            if (i != j) {
                adj[i].push_back(j);
            }
        }
    }
    return adj;
}