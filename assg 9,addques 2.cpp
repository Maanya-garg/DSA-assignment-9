#include <iostream>
using namespace std;
int M, N;
char grid[20][20];
bool visited[20][20];
void dfs(int r, int c) {
    if (r < 0 || r >= M || c < 0 || c >= N) return;
    if (grid[r][c] == '0' || visited[r][c]) return;
    visited[r][c] = true;
    dfs(r+1, c);
    dfs(r-1, c);
    dfs(r, c+1);
    dfs(r, c-1);
}
int main() {
    cin >> M >> N;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> grid[i][j];
    int islands = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == '1' && !visited[i][j]) {
                islands++;
                dfs(i, j);
            }
        }
    }
    cout << islands;
}
