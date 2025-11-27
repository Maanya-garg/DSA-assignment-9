#include <bits/stdc++.h>
using namespace std;

int shortestPathGrid(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();

    // Min-heap: (cost, x, y)
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    dist[0][0] = grid[0][0];

    pq.push({grid[0][0], 0, 0});

    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    while (!pq.empty()) {
        auto top = pq.top(); pq.pop();
        int cost = top[0], x = top[1], y = top[2];

        if (x == m-1 && y == n-1) return cost;

        for (auto &d : dirs) {
            int nx = x + d[0];
            int ny = y + d[1];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

            int newCost = cost + grid[nx][ny];
            if (newCost < dist[nx][ny]) {
                dist[nx][ny] = newCost;
                pq.push({newCost, nx, ny});
            }
        }
    }
    return -1;
}

int main() {
    vector<vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << shortestPathGrid(grid) << endl; // Output: 21
    return 0;
}
? 3. Network Delay Time
