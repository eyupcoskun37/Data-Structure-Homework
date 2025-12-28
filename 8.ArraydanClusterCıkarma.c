#include <stdio.h>

#define N 5   // node sayısı

/* DFS fonksiyonu */
void dfs(int graph[N][N], int visited[], int node) {
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < N; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(graph, visited, i);
        }
    }
}

/* Cluster (Connected Component) bulma */
void findClusters(int graph[N][N]) {
    int visited[N] = {0};
    int clusterNo = 1;

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            printf("Cluster %d: ", clusterNo++);
            dfs(graph, visited, i);
            printf("\n");
        }
    }
}

/* MAIN */
int main() {
    int graph[N][N] = {
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };

    findClusters(graph);

    return 0;
}
