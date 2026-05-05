#include <stdio.h>
#include <stdlib.h>

int minimumMoves(int n, char grid[n][n], int startX, int startY, int goalX, int goalY) {
    int dist[101][101];

    // Initialize distance array
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = -1;

    // Queue for BFS
    int qx[10001], qy[10001];
    int front = 0, rear = 0;

    // Start position
    qx[rear] = startX;
    qy[rear] = startY;
    rear++;
    dist[startX][startY] = 0;

    // Directions: up, down, left, right
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (front < rear) {
        int x = qx[front];
        int y = qy[front];
        front++;

        // Goal reached
        if (x == goalX && y == goalY)
            return dist[x][y];

        // Explore all 4 directions
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            // Slide in that direction
            while (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] != 'X') {
                if (dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    qx[rear] = nx;
                    qy[rear] = ny;
                    rear++;
                }
                nx += dx[d];
                ny += dy[d];
            }
        }
    }

    return -1; // If unreachable
}

int main() {
    int n;
    scanf("%d", &n);

    char grid[101][101];

    // Input grid
    for (int i = 0; i < n; i++) {
        scanf("%s", grid[i]);
    }

    int startX, startY, goalX, goalY;
    scanf("%d %d %d %d", &startX, &startY, &goalX, &goalY);

    int result = minimumMoves(n, grid, startX, startY, goalX, goalY);

    printf("%d\n", result);

    return 0;
}