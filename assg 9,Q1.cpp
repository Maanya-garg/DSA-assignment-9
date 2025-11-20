#include <iostream>
#include <queue>
using namespace std;
class Graph {
public:
    int V;
    int adj[20][20];   // max 20 nodes (change if needed)
    Graph(int V) {
        this->V = V;
        // initialize all edges to 0
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                adj[i][j] = 0;
    }
    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1;   // remove for directed graph
    }
    // BFS
    void BFS(int start) {
        bool visited[20] = {false};
        queue<int> q;
        visited[start] = true;
        q.push(start);
        cout << "BFS: ";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";
            // check all neighbours
            for (int i = 0; i < V; i++) {
                if (adj[node][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }
    // DFS (recursive)
    void DFSUtil(int node, bool visited[]) {
        visited[node] = true;
        cout << node << " ";
        for (int i = 0; i < V; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                DFSUtil(i, visited);
            }
        }
    }
    void DFS(int start) {
        bool visited[20] = {false};
        cout << "DFS: ";
        DFSUtil(start, visited);
        cout << endl;
    }
};
int main() {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.BFS(0);
    g.DFS(0);
    return 0;
}
