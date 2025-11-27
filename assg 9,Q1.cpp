#include <bits/stdc++.h>
using namespace std;
void BFS(int start, vector<vector<int>>& adj, int n) {
    vector<bool> visited(n, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);
    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
}
void DFSUtil(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " ";
    for (int v : adj[u]) {
        if (!visited[v])
            DFSUtil(v, adj, visited);
    }
}
void DFS(int start, vector<vector<int>>& adj, int n) {
    vector<bool> visited(n, false);
    cout << "DFS Traversal: ";
    DFSUtil(start, adj, visited);
    cout << endl;
}
struct Edge {
    int u, v, w;
};

bool compareEdges(Edge a, Edge b) {
    return a.w < b.w;
}

int findSet(int v, vector<int>& parent) {
    if (v == parent[v]) 
        return v;
    return parent[v] = findSet(parent[v]);  // Path compression
}

void unionSet(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = findSet(a, parent);
    b = findSet(b, parent);

    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;

        if (rank[a] == rank[b])
            rank[a]++;
    }
}

void Kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compareEdges);

    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    cout << "Kruskal MST Edges:\n";

    int cost = 0;
    for (auto& e : edges) {
        if (findSet(e.u, parent) != findSet(e.v, parent)) {
            cout << e.u << " -- " << e.v << " (Weight " << e.w << ")\n";
            cost += e.w;
            unionSet(e.u, e.v, parent, rank);
        }
    }

    cout << "Total Cost of MST (Kruskal): " << cost << "\n\n";
}
void Prim(int start, vector<vector<pair<int,int>>>& adj, int n) {
    vector<int> key(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> inMST(n, false);

    key[start] = 0;

    cout << "Prim MST Edges:\n";

    for (int i = 0; i < n - 1; i++) {
        int u = -1;

        // Pick the vertex with the smallest key value
        for (int v = 0; v < n; v++) {
            if (!inMST[v] && (u == -1 || key[v] < key[u]))
                u = v;
        }

        inMST[u] = true;

        for (auto& p : adj[u]) {
            int v = p.first;
            int w = p.second;

            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
            }
        }
    }

    int cost = 0;
    for (int v = 0; v < n; v++) {
        if (parent[v] != -1) {
            cout << parent[v] << " -- " << v << " (Weight " << key[v] << ")\n";
            cost += key[v];
        }
    }

    cout << "Total Cost of MST (Prim): " << cost << "\n\n";
}
void Dijkstra(int start, vector<vector<pair<int,int>>>& adj, int n) {
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);

    dist[start] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int v = 0; v < n; v++)
            if (!visited[v] && (u == -1 || dist[v] < dist[u]))
                u = v;

        visited[u] = true;

        for (auto& p : adj[u]) {
            int v = p.first;
            int w = p.second;

            if (dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    cout << "Dijkstra Shortest Distances from " << start << ":\n";
    for (int i = 0; i < n; i++)
        cout << "Vertex " << i << " : " << dist[i] << endl;
}
int main() {
    int n = 6;

    // For BFS/DFS adjacency list
    vector<vector<int>> adjList(n);

    // Undirected graph example
    adjList[0] = {1, 2};
    adjList[1] = {0, 3};
    adjList[2] = {0, 3};
    adjList[3] = {1, 2, 4};
    adjList[4] = {3, 5};
    adjList[5] = {4};

    // Weighted graph for MST + Dijkstra
    vector<Edge> edges = {
        {0,1,4}, {0,2,4}, {1,2,2}, {1,3,5},
        {2,3,1}, {3,4,3}, {4,5,6}
    };

    vector<vector<pair<int,int>>> weightedAdj(n);
    for (auto& e : edges) {
        weightedAdj[e.u].push_back({e.v, e.w});
        weightedAdj[e.v].push_back({e.u, e.w});
    }

    BFS(0, adjList, n);

    DFS(0, adjList, n);

    Kruskal(n, edges);

    Prim(0, weightedAdj, n);

    Dijkstra(0, weightedAdj, n);
    return 0;
}

