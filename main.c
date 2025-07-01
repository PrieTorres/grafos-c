#include <stdio.h>
#include <stdlib.h>

#define VERTICES 10
#define INF 1000000000

/*
 * Implementacao simples do algoritmo de Dijkstra para grafos nao-direcionados
 * com pesos positivos representados por matriz de adjacencia.
 */

void dijkstra(int graph[VERTICES][VERTICES], int start, int end) {
    int dist[VERTICES];
    int prev[VERTICES];
    int visited[VERTICES];

    for (int i = 0; i < VERTICES; i++) {
        dist[i] = INF;
        prev[i] = -1;
        visited[i] = 0;
    }
    dist[start] = 0;

    for (int count = 0; count < VERTICES - 1; count++) {
        int min = INF, u = -1;
        for (int v = 0; v < VERTICES; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                u = v;
            }
        }

        if (u == -1) break; // nao ha vertices alcancaveis restantes
        visited[u] = 1;

        for (int v = 0; v < VERTICES; v++) {
            if (!visited[v] && graph[u][v] != INF && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }

    if (dist[end] == INF) {
        printf("Nao existe caminho entre %d e %d\n", start + 1, end + 1);
        return;
    }

    printf("Custo total: %d\n", dist[end]);
    printf("Caminho: ");

    int path[VERTICES];
    int size = 0;
    for (int v = end; v != -1; v = prev[v]) {
        path[size++] = v;
    }
    for (int i = size - 1; i >= 0; i--) {
        printf("%d", path[i] + 1);
        if (i) printf(" -> ");
    }
    printf("\n");
}

int main() {
    int graph[VERTICES][VERTICES];

    // inicializa a matriz com INF e zero na diagonal
    for (int i = 0; i < VERTICES; i++) {
        for (int j = 0; j < VERTICES; j++) {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }

    int edges;
    printf("Numero de arestas: ");
    if (scanf("%d", &edges) != 1) return 1;
    for (int i = 0; i < edges; i++) {
        int a, b, w;
        printf("Aresta %d (origem destino peso): ", i + 1);
        if (scanf("%d %d %d", &a, &b, &w) != 3) return 1;
        if (a < 1 || a > VERTICES || b < 1 || b > VERTICES || w < 0) {
            printf("Entrada invalida.\n");
            return 1;
        }
        // converte para indices iniciados em 0
        a--; b--;
        graph[a][b] = w;
        graph[b][a] = w;
    }

    int start, end;
    printf("Vertice de origem (1-%d): ", VERTICES);
    if (scanf("%d", &start) != 1) return 1;
    printf("Vertice de destino (1-%d): ", VERTICES);
    if (scanf("%d", &end) != 1) return 1;
    if (start < 1 || start > VERTICES || end < 1 || end > VERTICES) {
        printf("Vertices invalidos.\n");
        return 1;
    }

    dijkstra(graph, start - 1, end - 1);
    return 0;
}

