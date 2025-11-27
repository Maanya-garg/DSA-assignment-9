#include <bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int,int>>> adj(n+1);

    for (auto &t : times) {
        int u = t[0], v = t[1], w = t[2];
        adj[u].push_back({v, w});
    }

    vector<int> dist(n+1, INT_MAX);
    dist[k] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, k});

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        if (d > dist[node]) continue;

        for (auto &edge : adj[node]) {
            int next = edge.first;
            int w = edge.second;
            if (dist[node] + w < dist[next]) {
                dist[next] = dist[node] + w;
                pq.push({dist[next], next});
            }
        }
    }

    int ans = *max_element(dist.begin() + 1, dist.end());
    return (ans == INT_MAX ? -1 : ans);
}

int main() {
    int n = 4, k = 2;
    vector<vector<int>> times = {
        {2, 1, 1},
        {2, 3, 1},
        {3, 4, 1}
    };

    cout << networkDelayTime(times, n, k) << endl; // Output: 2
    return 0;
}
