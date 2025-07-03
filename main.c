#include <stdio.h>
#include <stdlib.h>

#define VERTICES 10
#define INF 1000000000  // Usado para representar "distância infinita" (sem ligação direta)

// Função que executa o algoritmo de Dijkstra para encontrar o menor caminho
void calcula(int graph[VERTICES][VERTICES], int start, int end) {
    int dist[VERTICES];    // Armazena a menor distância conhecida do start a cada vértice
    int prev[VERTICES];    // Armazena o vértice anterior no menor caminho
    int visited[VERTICES]; // Marca os vértices já visitados/finalizados

    // Inicialização dos vetores
    for (int i = 0; i < VERTICES; i++) {
        dist[i] = INF;   // Distância desconhecida (infinita)
        prev[i] = -1;    // Sem vértice anterior conhecido
        visited[i] = 0;  // Nenhum vértice foi visitado ainda
    }
    dist[start] = 0;  // Distância do ponto inicial para ele mesmo é zero

    // Repetição para processar todos os vértices
    for (int count = 0; count < VERTICES - 1; count++) {
        int min = INF;
        int u = -1;

        // Escolhe vértice u com menor distância ainda não visitado
        for (int v = 0; v < VERTICES; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                u = v;
            }
        }

        if (u == -1) // Se não há vértice alcançável restante, termina o loop
            break;

        visited[u] = 1; // Marca o vértice como visitado

        // Atualiza as distâncias dos vizinhos de u
        for (int v = 0; v < VERTICES; v++) {
            // Se não visitado, existe ligação, e caminho via u é menor, atualiza dist[v]
            if (!visited[v] && graph[u][v] != INF && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;  // Salva que para chegar em v, veio de u
            }
        }
    }

    // Verifica se existe caminho até o destino
    if (dist[end] == INF) {
        printf("Nao existe caminho entre %d e %d\n", start + 1, end + 1);
        return;
    }

    // Imprime o custo total do caminho encontrado
    printf("Custo total: %d\n", dist[end]);
    printf("Caminho: ");

    // Reconstrói o caminho do destino para origem usando prev[]
    int path[VERTICES];
    int size = 0;
    for (int v = end; v != -1; v = prev[v]) {
        path[size++] = v;
    }

    // Imprime o caminho na ordem correta (origem -> destino)
    for (int i = size - 1; i >= 0; i--) {
        printf("%d", path[i]);
        if (i != 0) printf(" -> ");
    }
    printf("\n");
}

// Inicializa o grafo com 0 na diagonal e INF para outros pares
void inicializa_grafo(int graph[VERTICES][VERTICES]) {
    for (int i = 0; i < VERTICES; i++) {
        for (int j = 0; j < VERTICES; j++) {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }
}

void monta_grafo_exemplo1(int graph[VERTICES][VERTICES]) {
    // Joinville=0, Curitiba=1, SP=2, RJ=3, BH=4
    graph[0][1] = graph[1][0] = 50;
    graph[1][2] = graph[2][1] = 100;
    graph[2][3] = graph[3][2] = 150;
    graph[3][4] = graph[4][3] = 100;
    graph[0][2] = graph[2][0] = 300;
    graph[2][4] = graph[4][2] = 400;
    graph[1][3] = graph[3][1] = 200;
}

// Monta um grafo de exemplo (10 vértices com nomes fictícios)
void monta_grafo_exemplo2(int graph[VERTICES][VERTICES]) {
    // Cidades:
    // 0 - Porto Alegre
    // 1 - Florianópolis
    // 2 - Curitiba
    // 3 - São Paulo
    // 4 - Rio de Janeiro
    // 5 - Belo Horizonte
    // 6 - Brasília
    // 7 - Salvador
    // 8 - Fortaleza
    // 9 - Recife

    graph[0][1] = graph[1][0] = 300;
    graph[1][2] = graph[2][1] = 200;
    graph[2][3] = graph[3][2] = 400;
    graph[3][4] = graph[4][3] = 430;
    graph[4][5] = graph[5][4] = 440;
    graph[5][6] = graph[6][5] = 720;
    graph[6][7] = graph[7][6] = 1000;
    graph[7][8] = graph[8][7] = 1200;
    graph[8][9] = graph[9][8] = 650;

    graph[0][2] = graph[2][0] = 500;
    graph[1][3] = graph[3][1] = 700;
    graph[2][5] = graph[5][2] = 900;
    graph[4][7] = graph[7][4] = 1500;
    graph[6][9] = graph[9][6] = 1300;
}

int main() {
    int graph[VERTICES][VERTICES];
    int escolha;

    inicializa_grafo(graph);

    printf("Escolha o grafo de teste:\n");
    printf("1 - Grafo Joinville-BH\n");
    printf("2 - Outro grafo de exemplo\n");
    printf("Opcao: ");
    if (scanf("%d", &escolha) != 1) return 1;

    if (escolha == 1) {
        monta_grafo_exemplo1(graph);
    } else if (escolha == 2) {
        monta_grafo_exemplo2(graph);
    } else {
        printf("Opcao invalida.\n");
        return 1;
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

    calcula(graph, start - 1, end - 1);

    return 0;
}
