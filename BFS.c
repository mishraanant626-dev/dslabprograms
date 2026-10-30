
#include <stdio.h>

int graph[20][20], visited[20], n;

void DFS(int v) {
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i])
            DFS(i);
    }
}

void BFS(int start) {
    int queue[20], front = 0, rear = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (graph[v][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS: ");
    BFS(start);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nDFS: ");
    DFS(start);

    return 0;
}
