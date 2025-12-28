#include <stdio.h>

#define N 5

/* ---------- DFS ---------- */
void DFS(int graph[N][N], int visited[], int node) {
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < N; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            DFS(graph, visited, i);
        }
    }
}

/* ---------- BFS ---------- */
void BFS(int graph[N][N], int start) {
    int visited[N] = {0};
    int queue[N], front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < N; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

/* ---------- MAIN ---------- */
int main() {
    int graph[N][N] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {0, 0, 0, 1, 0}
    };

    int visited[N] = {0};

    printf("DFS (0'dan basla): ");
    DFS(graph, visited, 0);

    printf("\nBFS (0'dan basla): ");
    BFS(graph, 0);

    return 0;
}
