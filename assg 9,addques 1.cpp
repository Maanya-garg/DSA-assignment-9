#include <iostream>
using namespace std;
int adj[20][20];
bool visited[20];
int V, E;
void dfs(int node) {
    visited[node] = true;
    for (int i = 0; i < V; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}
int main() {
    cin >> V >> E;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;   
    }
    for (int i = 0; i < V; i++) visited[i] = false;
    int components = 0;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            components++;
            dfs(i);
        }
    }
    cout << components;
}
